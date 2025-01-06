LaneLabelingTool**车道视频标注工具**，主要用于标注行车记录仪视频中的车道总数及当前所在车道序号信息，开发环境VS2022+Qt6.8。
## 1 使用
> （1）点击左上角打开视频文件。<br/>
![主界面展示](../images/main.png)<br/>
> （2）支持音量调节、进度调节、上一帧、下一帧、播放、暂停、停止的基本功能。<br/>
![打开视频后界面展示](../images/add.png)<br/>
> （3）如已有标注，会显示在标注各信息栏中。<br/>
![修改标注界面展示](../images/edit.png)<br/>
> （4）标注方式1-新增（当前无标注记录）：<br/>
![新增标注界面展示](../images/add.png)<br/>
&emsp;&emsp;&emsp;点击设置首帧，此时视频暂停，首帧栏记录首帧数据；<br/>
&emsp;&emsp;&emsp;跳转需标注尾帧位置，点击设置尾帧，此时视频暂停，尾帧栏记录尾帧数据；<br/>
&emsp;&emsp;&emsp;此时可修改首帧、尾帧数据；<br/>
&emsp;&emsp;&emsp;键入标注车道信息；<br/>
&emsp;&emsp;&emsp;点击保存按钮，数据录入视频同名同级csv文件；点击取消按钮，视频继续播放并取消刚刚的标注信息。<br/> 
> （5）标注方式2-修改（当前已有标注记录）：<br/>
![修改标注界面展示](../images/edit.png)<br/>
&emsp;&emsp;&emsp;点击修改，此时视频暂停；<br/>
&emsp;&emsp;&emsp;修改首帧、尾帧、车道信息；<br/>
&emsp;&emsp;&emsp;点击保存按钮，数据录入视频同名同级csv文件；点击取消按钮，视频继续播放并取消刚刚的标注信息。<br/> 
![保存或取消标注界面展示](../images/save.png)<br/>

## 2 打包说明
> （1）生成后，在./x64/Release/下执行获取依赖库：<br/>
xxx\Qt6\6.8.0\msvc2022_64\bin\windeployqt.exe .\LaneLabelingTool.exe<br/>
> （2）整个目录打包即可或者Microsoft Visual Studio Installer Project插件打包<br/>

## 3 Release产物
> Release文件夹下：<br/>
&emsp;&emsp;msi安装包：安装使用；<br/>
&emsp;&emsp;exe文件：如已安装，直接替换exe。<br/>