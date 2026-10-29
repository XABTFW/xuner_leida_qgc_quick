# xuner_leida_qgc_quick

本仓库的 `main` 保存当前可构建的定制地面站源码，基于 QGroundControl 和原项目的
`tianhe_dyt_net_qgc` 分支，包含雷达 UDP 桥接、目标编号配置、雷达诊断日志、
SDM50/DYT 界面、PX4 参数缓存快速重连及 Windows 图形初始化修复。

```powershell
git clone --recurse-submodules -b main https://github.com/XABTFW/xuner_leida_qgc_quick.git
cd xuner_leida_qgc_quick
```

Windows 已验证环境：Qt 6.8.3、MSVC 2022 x64、CMake/Ninja、GStreamer 1.22.12。
在 Qt Creator 中打开根目录 `CMakeLists.txt`，选择对应 Kit。使用软件 OpenGL 的电脑或
虚拟机，在 CMake 配置中启用 `QGC_WINDOWS_SOFTWARE_OPENGL=ON`。

自定义 MAVLink C 头文件已随源码保存在 `third_party/mavlink`，默认直接使用，不需要从
其他电脑的 `build` 目录复制。GPS 驱动与 libevents 已固定兼容版本。历史说明中的
切换 `master`、手动替换 MAVLink/GPS 操作不适用于当前 `main`。

- 雷达配置：[docs/RadarBridge.txt](docs/RadarBridge.txt)
- PX4 参数缓存、安装与回滚：[docs/ParameterCache.txt](docs/ParameterCache.txt)
- Windows 图形配置：[docs/WindowsGraphics.txt](docs/WindowsGraphics.txt)

仓库包含源码、资源、文档、测试和必要协议头文件；构建目录、运行缓存及本地源码备份不提交。
上游项目介绍和授权信息保留如下。

---

<p align="center">
  <img src="https://raw.githubusercontent.com/Dronecode/UX-Design/35d8148a8a0559cd4bcf50bfa2c94614983cce91/QGC/Branding/Deliverables/QGC_RGB_Logo_Horizontal_Positive_PREFERRED/QGC_RGB_Logo_Horizontal_Positive_PREFERRED.svg" alt="QGroundControl Logo" width="500">
</p>

<p align="center">
  <a href="https://github.com/mavlink/QGroundControl/releases">
    <img src="https://img.shields.io/github/release/mavlink/QGroundControl.svg" alt="Latest Release">
  </a>
</p>

*QGroundControl* (QGC) is a highly intuitive and powerful Ground Control Station (GCS) designed for UAVs. Whether you're a first-time pilot or an experienced professional, QGC provides a seamless user experience for flight control and mission planning, making it the go-to solution for any *MAVLink-enabled drone*.

---

### 🌟 *Why Choose QGroundControl?*

- *🚀 Ease of Use*: A beginner-friendly interface designed for smooth operation without sacrificing advanced features for pros.
- *✈️ Comprehensive Flight Control*: Full flight control and mission management for *PX4* and *ArduPilot* powered UAVs.
- *🛠️ Mission Planning*: Easily plan complex missions with a simple drag-and-drop interface.

🔍 For a deeper dive into using QGC, check out the [User Manual](https://docs.qgroundcontrol.com/en/) – although, thanks to QGC's intuitive UI, you may not even need it!


---

### 🚁 *Key Features*

- 🕹️ *Full Flight Control*: Supports all *MAVLink drones*.
- ⚙️ *Vehicle Setup*: Tailored configuration for *PX4* and *ArduPilot* platforms.
- 🔧 *Fully Open Source*: Customize and extend the software to suit your needs.

🎯 Check out the latest updates in our [New Features and Release Notes](https://github.com/mavlink/qgroundcontrol/blob/master/ChangeLog.md).

---

### 💻 *Get Involved!*

QGroundControl is *open-source*, meaning you have the power to shape it! Whether you're fixing bugs, adding features, or customizing for your specific needs, QGC welcomes contributions from the community.

🛠️ Start building today with our [Developer Guide](https://dev.qgroundcontrol.com/en/) and [build instructions](https://dev.qgroundcontrol.com/en/getting_started/).

---

### 🔗 *Useful Links*

- 🌐 [Official Website](http://qgroundcontrol.com)
- 📘 [User Manual](https://docs.qgroundcontrol.com/en/)
- 🛠️ [Developer Guide](https://dev.qgroundcontrol.com/en/)
- 💬 [Discussion & Support](https://docs.qgroundcontrol.com/en/Support/Support.html)
- 🤝 [Contributing](https://dev.qgroundcontrol.com/en/contribute/)
- 📜 [License Information](https://github.com/mavlink/qgroundcontrol/blob/master/.github/COPYING.md)

---

With QGroundControl, you're in full command of your UAV, ready to take your missions to the next level.
