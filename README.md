# 機房預約系統

用於學校機房預約管理。系統允許不同類型的用戶（學生、老師和管理員）執行與機房預約相關的各種操作。

## 功能

- **學生**:
  - 申請預約。
  - 查看個人預約。
  - 查看所有預約。
  - 取消預約。

- **老師**:
  - 查看所有學生的預約。
  - 審核（通過或拒絕）預約。

- **管理員**:
  - 添加學生或老師帳號。
  - 查看所有學生和老師帳號。
  - 查看機房信息。
  - 清空所有預約記錄。
  - 
## 文件結構

- **main.cpp**: 包含主函數和程序的入口點。
- **identity.h**: 定義 `Identity` 基類。
- **student.h/cpp**: 定義 `Student` 類及其方法。
- **teacher.h/cpp**: 定義 `Teacher` 類及其方法。
- **manager.h/cpp**: 定義 `Manager` 類及其方法。
- **computerRoom.h**: 定義 `ComputerRoom` 類。
- **orderFile.h/cpp**: 管理預約記錄。
- **globalfile.h**: 包含不同用戶和預約文件的文件路徑定義。

- ## 文件說明

- **admin.txt**: 存儲管理員資訊。
- **student.txt**: 存儲學生資訊。
- **teacher.txt**: 存儲老師資訊。
- **computerRoom.txt**: 存儲機房資訊。
- **order.txt**: 存儲預約記錄。

- 確保在項目目錄中創建以下數據文件，或修改 globalfile.h的數據文件：

admin.txt: adminName adminPassword  
student.txt: studentId studentName studentPassword  
teacher.txt: teacherId teacherName teacherPassword  
computerRoom.txt: roomId maxCapacity  
order.txt: date:weekDay interval:timePeriod stuId:studentId stuName:studentName roomId:roomId status:reservationStatus
