# Wookong Solo - RUST

## UART interface signer for Linux and MacOS

With CP210X:
Linux already has the driver.
For mac, plz install the driver in .zip

## Call in RUST

```
extern crate solo;
...
 fn hd_getpub(&self) ->  HDWalleResult<Public>{
        let mut pk:[u8;32] = [0u8;32];
        let rv = wk_getpub(&mut pk);
        if rv==242{
            return Err(HDWalletError::DeviceNotInit);
        }else if rv!=0{
            return Err(HDWalletError::DeviceNotfound);
        }else if rv==0{
            Ok(sr25519::Public::from_raw(pk))
        }else{
            return Err(HDWalletError::DeviceError);
        }
    }
...
```

### multi seed

Allow multi seed, max 128. All seed will be indexed by 0~127.
Select which seed to use by using solo_select. Given account/pubkey and derive path to search the right seed.
If found. The device will set the seed and derive path as default. Sign and getpub will use it if there is no more input to set.

If users do not select any seed and give any derive path, device will use the first seed and default derive path 

