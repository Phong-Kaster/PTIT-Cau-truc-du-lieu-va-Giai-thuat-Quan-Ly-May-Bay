# PTIT-Quan-ly-may-bay-Cau-truc-du-lieu-va-Giai-thuat-Luu-Nguyen-Ki-Thu
Mình tên là Nguyễn Thành Phong.Mã N18DCCN147.Lớp D18CQCN03-N.Khóa 2018-2023

Nhắc đến học IT ở PTIT mà hông nhắc tới môn này thì thật là thiếu sót.
Đây là đồ án quản lý máy bay kì 2 năm 2 (2020)Môn cấu trúc dữ liệu và giải thuật do thầy Lưu Nguyễn Kì Thư dạy lớp mình.

Đây thực sự là môn mà mình thấy khó nhất trường PTIT này.Qua môn phải nói là siêu ít lớp mình có 83 người thì tầm khoảng 20 người qua là hết cỡ (><)(NÓI CHUNG LÀ TOANG )
Chả thế mà nhiều thế hệ gắn ổng cái nick name Lưu Mãi Kì Thi cũng đúng

Mình chia sẻ phần đồ này hi vọng giúp các tân binh khóa sau có thể vượt qua môn này dễ nhất . Đồ án này gồm nhiều thành phần và thư viện được tích hợp thành 1 bài hoàn chỉnh

Để tham khảo bài mình hiệu quả các bạn hãy đọc code theo trình tự như sau và xem hình ảnh demo để hình dung các bạn sẽ làm gì 
( do thời điểm mình viết là 12-04-2021 , lúc này kì 2 năm 3 rồi nên có thể không nhớ chính xác trình tự ^^ )

1.MyLibraryTP - thư viện mẫu chứa các hàm để vẽ điểm , thay đổi màu sắc , nói chung là muốn vẽ trên cosole thì phải có như viện này  blah...blah

2.UserInterfaceTP - chỗ này mình dùng để dựng lên menu và gắn các nút mũi tên để di chuyển lên xuống giữa các các tùy chọn

3.GlobalVariableTP - lưu toàn bộ biến toàn cuc

4.ConstraintTP - các ràng buộc được xây dựng ,ví dụ như nhập tên người thì không có được ghi số , số điện thoại thì hông được ghi chữ cái ...vân vân và mây mây

5.AirplaneTP - xử lý cho việc tạo thêm - xóa - sửa máy bay 

6.FlightTP - xử lý cho việc tạo - thêm - xóa - sửa chuyến bay

7.DataTimeTP - xử lý ngày giờ

8.PassengerTP - chứa thông tin của 1 hành khách , phục vụ cho việc đặt vé

9.ProcessionTP - phần kết của đồ án, chủ yếu làm cho màu mè chứ không có cũng chẳng sao ^^,trong này viết các hàm đọc file để hiện lên phần intro và outro cho đồ án
nhưng thầy cũng không để ý phần này nhìu đâu nha ^^

Mình hy vọng đồ án này có thể giúp các bạn khóa sau có thể vượt qua môn này dễ dàng nhất có thể ( vì môn này khó vl , mình cũng làm vỡ mặt mới qua ^^ ).

Nếu qua được thì xin CHÚC MỪNG BẠN vì nếu qua được môn này của thầy thì bạn hoàn toàn có thể theo đuổi ngành IT nha.Nhiều bạn kêu thầy khó 
nhưng thực ra thì thầy làm vậy là tốt cho chúng mình á , các bạn đừng oán thầy nha.
Chúc các bạn khóa sau khi đọc được bài này của mình nhiều may mắn và sức khỏe nha - Mon,12-04-2021

MỘT SỐ HÌNH ẢNH MINH HỌA!

1)Màn hình intro nè !!
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_Z2FPblh3oM" src="https://user-images.githubusercontent.com/58034430/119598518-4d8ef980-be0d-11eb-9e9b-b1ddf40dc94b.png">


2)Màn hình menu chính
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_BmTWFPVOLY" src="https://user-images.githubusercontent.com/58034430/119598488-3d771a00-be0d-11eb-8cb1-d41b99b7a7b0.png">

<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_BrvBxJQm89" src="https://user-images.githubusercontent.com/58034430/119598541-58e22500-be0d-11eb-9bd6-c5d0698b5461.png">

3)Màn hình quản lý máy bay
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_Q1LQEK0fdW" src="https://user-images.githubusercontent.com/58034430/119598662-8e870e00-be0d-11eb-978b-7ad826aa584f.png">

4)Màn hình quản lý chuyến bay
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_9S3QPTXLuI" src="https://user-images.githubusercontent.com/58034430/119598675-93e45880-be0d-11eb-896e-45a2f964e8b4.png">

5)Màn hình kiểm tra thông tin chuyến bay
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_uavjIiuqdC" src="https://user-images.githubusercontent.com/58034430/119598723-aced0980-be0d-11eb-8cb3-912017767d5f.png">

6)Màn hình danh sách hành khách của chuyến bay 
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_YLjx8ojtSd" src="https://user-images.githubusercontent.com/58034430/119598771-c2623380-be0d-11eb-9e90-514c14b84073.png">

7)Màn hình liệt kê số chuyến bay đã thực hiện
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_rY5Jjq4VoX" src="https://user-images.githubusercontent.com/58034430/119598801-d312a980-be0d-11eb-979c-7ec205041a5d.png">

8)Màn hình sơ đồ chỗ ngồi , đặt vé
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_8zuCtrJ5ee" src="https://user-images.githubusercontent.com/58034430/119598899-0d7c4680-be0e-11eb-82ce-accb575c2703.png">

9)Màn hình kết thúc
<img width="960" alt="Quan_Ly_May_Bay_-_Last_fix_iopZYOlSQ5" src="https://user-images.githubusercontent.com/58034430/119598925-1d942600-be0e-11eb-9fca-ad51b96a8d3e.png">


Mình viết chương trình này trên Visual Ultimate Code 2010 nhưng mình đã cập nhật lại core của ngôn ngữ C++ mới nhất.Nên các bạn hoàn toàn có thể an tâm tải về lại chạy được ngay nha （￣︶￣）↗　
