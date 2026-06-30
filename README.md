# XMU暑期学期 电子工艺实训业务代码

详见
`src/applications/sample/wifi-iot/app`

- `/first_app`为第一课
- `/led_demo`为第二课
- 

关于编译
若想编译某个项目的代码需要修改`src/applications/sample/wifi-iot/app`下的`BUILD.gn`
例如：
要编译led_demo则修改`BUILD.gn`中的`features`为

```
    features = [
        "led_demo:led_demo", 
    ]
   /*
      前一个led_demo为相对路径，指向src/applications/sample/wifi-iot/app/led_demo/BUILD.gn
      后一个led_demo为目标，指向src/applications/sample/wifi-iot/app/led_demo/BUILD.gn中的static_library("led_demo")
   */
```

