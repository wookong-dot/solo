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
