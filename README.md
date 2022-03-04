<h1 align="center">Cấu Trúc Dữ Liệu Và Giải Thuật<br/>
    Đề tài: Quản Lý Máy Bay
</h1>

<p align="center">
    <img src="./HinhAnhDemoDoAnCuaMinh/cover.jpg" width="1280" />
</p>

# [**Table Of Content**](#table-of-content)
- [**Table Of Content**](#table-of-content)
- [**Introduction**](#introduction)
- [**Architecture**](#architecture)
- [**Illustrating Images**](#illustrating-images)
- [**Frequently Asked Questions**](#frequently-asked-questions)
- [**How to score yourself**](#how-to-score-yourself)
- [**Special Thank**](#special-thank)
- [**Post Script**](#post-script)
# [**Introduction**](#introduction)
Mình tên là Nguyễn Thành Phong. Mã N18DCCN147. Lớp D18CQCN03-N. Khóa 2018-2023

Nhắc đến học IT ở PTIT mà hông nhắc tới môn này thì thật là thiếu sót.
Đây là đồ án quản lý máy bay kì 2 năm 2 (2020) môn cấu trúc dữ liệu và giải thuật do thầy Lưu Nguyễn Kì Thư dạy lớp mình.

Đây thực sự là môn mà mình thấy khó nhất trường PTIT này - cho tới khi các bạn học [**Cơ sở dữ liệu phân tán**](https://github.com/Phong-Kaster/PTIT-Co-So-Du-Lieu-Phan-Tan-Quan-Ly-Vat-Tu) ở năm cuối đại học thì sẽ ăn hành ở 1 tầm cao mới 😅. Qua được môn phải nói là siêu ít, lớp mình có 83 người thì tầm khoảng 20 người qua là hết cỡ 😐(NÓI CHUNG LÀ TOANG )
Chả thế mà nhiều thế hệ gắn ổng cái nick name Lưu Mãi Kì Thi cũng đúng 😂😂

Mình chia sẻ phần đồ này hi vọng giúp các tân binh khóa sau có thể vượt qua môn này dễ nhất . Đồ án này gồm nhiều thành phần và thư viện được tích hợp thành 1 bài hoàn chỉnh. Theo mình thấy, cái khó ở đây nằm ở chỗ trước đó chúng ta chỉ làm các bài tập đơn giản với 1 màn hình console duy nhất. Do vậy, khi tự dưng phải làm một đồ án lớn thì dễ bị nản và ngợp. Lúc mình học thì cũng có kha khá bạn bỏ thi vì lý do này.

# [**Architecture**](#architecture)
Để tham khảo bài mình hiệu quả các bạn hãy đọc code theo trình tự như sau và xem hình ảnh demo để hình dung các bạn sẽ làm gì 
( do thời điểm mình viết là 12-04-2021 , lúc này kì 2 năm 3 rồi nên có thể không nhớ chính xác trình tự 😎 )
1. MyLibraryTP - thư viện mẫu chứa các hàm để vẽ điểm , thay đổi màu sắc , nói chung là muốn vẽ trên cosole thì phải có như viện này  blah...blah

2. UserInterfaceTP - chỗ này mình dùng để dựng lên menu và gắn các nút mũi tên để di chuyển lên xuống giữa các các tùy chọn

3. GlobalVariableTP - lưu toàn bộ biến toàn cuc

4. ConstraintTP - các ràng buộc được xây dựng ,ví dụ như nhập tên người thì không có được ghi số , số điện thoại thì hông được ghi chữ cái ...vân vân và mây mây

5. AirplaneTP - xử lý cho việc tạo thêm - xóa - sửa máy bay 

6. FlightTP - xử lý cho việc tạo - thêm - xóa - sửa chuyến bay

7. DataTimeTP - xử lý ngày giờ

8. PassengerTP - chứa thông tin của 1 hành khách , phục vụ cho việc đặt vé

9. ProcessionTP - phần kết của đồ án, chủ yếu làm cho màu mè chứ không có cũng chẳng sao 😝,trong này viết các hàm đọc file để hiện lên phần intro và outro cho đồ án
nhưng thầy cũng không để ý phần này nhìu đâu nha 🥱

# [**Illustrating Images**](#illustrating-images)

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

# [**Frequently Asked Questions**](#frequently-asked-questions)
Frequently Asked Questions hay FAQ là câu hỏi thường gặp. Mình cũng thi khá lâu rồi nhưng vẫn nhớ được một số câu hỏi
mà thầy Lưu Nguyễn Kì Thư hay hỏi sinh viên chúng mình. Các câu hỏi của thầy sẽ đi bao gồm 4 cấp độ như sau:

Cấp 1 - Nhận biết: cấp độ này siêu dễ hiểu thầy sẽ hỏi các câu hỏi như:

	1.Biến nào thể hiện số lượng máy bay ?
	2.Biến nào thể hiện số lượng hành khách ?
	3.Số CMND|CCCD thì dùng kiểu dữ liệu là gì ?
	..........................

Cấp 2 - Thông hiểu: cấp này hỏi chủ yếu là lý thuyết

	1.Giải thích danh sách liên kết là gì ?
	2.Cây nhị phân cân bằng có cơ chế tự cân bằng số node ở 2 bên như nào ?
	3.Sự khác biệt giữa mảng con trỏ & mảng động
	4.Một số tính năng phụ trợ như có thể dùng phím mũi tên để di chuyển con trỏ lên xuống ở mục nhập thông tin được không ?
	5.Trước khi kết thúc yêu cầu thêm - xóa - sửa.Các bạn nên có 1 ô thông báo để xác nhận lại: Bạn có chắc chắn muốn thay đổi không ?
	..........................

Cấp 3 - Vận dụng: thầy sẽ yêu cầu chúng ta mở đoạn code có xử lý chức năng nào đó.Ví dụ như sử lý thêm - xóa - sửa máy bay.Tiếp đến, thầy sẽ hỏi rằng:

	1.Đoạn code đó có độ phức tạp là bao nhiêu ?
	2.Có mấy vòng lặp trong đoạn code này ?
	3.Đã bắt các ràng buộc được chưa ? Tên người thì không có số, số điện thoại thì không được ghi chữ cái,..........
	4.Một hành khách chỉ được phép mua 1 vé duy nhất / chuyến bay.
	5.Một hành khách không thể đặt mua vé trên 2 chuyến bay có cùng thời gian khởi hành
	..........................

Note: Với ý số 4 & số 5 la vô cùng QUAN TRỌNG. Nếu các bạn không bắt được tối thiểu 1 trong 2 ý này thì bài làm của các bạn sẽ bị mất rất nhiều điểm.

Cấp 4 - Vận dụng cao: Cuối cùng( Yeah 😂 cuối cùng cũng sắp thoát ải  ).

Thầy sẽ hỏi các bạn 1 câu siêu khó. Nếu trả lời được thì được cộng 0.5 điểm. Nếu không thì cũng không sao cả.
 Câu mình gặp mà mình vẫn nhớ đó là:

    - Trình bày cách sắp xếp 20000 số tự nhiên theo thứ tự từ bé đến lớn với mảng con trỏ ?
Câu này khó vl. Mình trả lời được 1 nửa đầu , nửa sau thì không đúng nên bị đánh hỏng😞

# [**How to score yourself**](#how-to-score-yourself)

Sau khi các bạn thi xong. Ổng thầy sẽ không chấm cho bạn điểm ngay lập tức để bạn biết đời mình nở hoa🌺 hay sẽ chuẩn bị tiền & tinh thần học lại. Thay vào đó, để tăng thêm phần kịch tính (và khả năng dày vò những đứa thi không thực sự tốt 😗 ), ổng sẽ cho bạn một cái mã số gồm 3 con số. Ví dụ: 049, 598,... Và bạn sẽ phải chờ dài cả cổ cho tới khi những đứa còn lại thi xong thì mới biết công thức tính điểm. 
Mình đã gần ra trường (04-03-2022) nên có một số công thức có thể coi là cố định để các bạn tự chấm trước cho mình như sau:

Mã điểm là a b c

Cách 1: ( b + c ) % 10

Cách 2: ( a + c) % 10

Cách 2: ( a + b + c ) % 10

Ví dụ: mã điểm là 5 3 1 thì theo

Cách 1: ( 3 + 1 ) % 10 = 0 dư 4. Tức bạn được 4 điểm.

Cách 2: ( 5 + 1 ) % 10 = 0 dư 6. Tức bạn được 6 điểm.

Cách 3: ( 5 + 3 + 1) % 10 = 0 dư 9. Tức bạn được 9 điểm.

Thông thường, cách 1 và cách 2 là phổ biến được sử dụng hơn cách 3.

# [**Special Thank**](#special-thank) 

<table>
    <tr>
        <td align="center">
        <a href="https://github.com/ngdanghau">
            <img src="./HinhAnhDemoDoAnCuaMinh/Hau.jpg" width="100px;" alt=""/>
            <br />
            <sub><b> Nguyen Dang Hau </b></sub>
        </a>
        <br />
    </td>
</table>
	
Phần này mình dành riêng để gửi lời cám ơn tới bạn [Nguyễn Đăng Hậu](https://www.facebook.com/anh.nhim.50). Bạn ấy vừa là một người bạn, vừa là một người thầy đối với mình. Suốt khoảng 3 tháng, từ tháng 03-2020 đến tháng 06-2020, kể từ khi nhận đề tài từ thầy, bạn Hậu đã chỉ dạy và giúp đỡ mình trong việc sửa chữa các đoạn chương trình vô cùng chi tiết và tỉ mỉ (vì làm đề tài một mình nên hơi bị đuối nữa). Nếu không có sự giúp đỡ nhiệt tình từ bạn Hậu, có lẽ mình đã không thể hoàn thiện một trong những đồ án lớn trong đời sinh viên PTIT của mình.😇😇
	
Ngoài ra, nếu các bạn làm để tài về Quản lý Sinh viên thì có thể tham khảo bài của bạn Hậu tại [đây](https://github.com/ngdanghau/quanlysinhvien) nha.
	
# [**Post Script**](#post-script)
Mình hy vọng đồ án này có thể giúp các bạn khóa sau có thể vượt qua môn này dễ dàng nhất có thể ( vì môn này khó vl , mình cũng làm vỡ mặt mới qua ^^ ).

Nếu đồ án & phần chú thích của mình giúp ích cho các bạn thì đừng ngần ngại tặng mình một ⭐ nha.

Nếu qua được thì xin CHÚC MỪNG BẠN vì nếu qua được môn này của thầy thì tương lai với ngành này của bạn rất triển vọng nha. Nhiều bạn kêu thầy khó.
Nhưng thực ra thì thầy làm vậy là tốt cho chúng mình á , các bạn đừng oán thầy nha.
Chúc các bạn khóa sau khi đọc được bài này của mình nhiều may mắn và sức khỏe nha - Mon, 12 April 2021

Mình viết chương trình này trên Visual Ultimate Code 2010 nhưng mình đã cập nhật lại core của ngôn ngữ C++ mới nhất.Nên các bạn hoàn toàn có thể an tâm tải về chạy được trên Visual Studio 2019 ( phiên bản mới nhất thời điểm mình viết ) ngay nha 😎😋😊
