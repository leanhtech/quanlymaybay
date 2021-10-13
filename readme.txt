PTITHCM_2ndYear_2ndSemester
Đồ Án CTDL&GT
Đề Tài : Quản lý các chuyến bay nội địa thuộc một hãng hàng không.
Sinh Viên Thực Hiện :
- Lê Hoàng Anh (N19DCCN005) : Thiết kết giao diện, tạo chức năng, code phần chính.
- Văn Dương Thanh Toán (N19DCCN172) : Sửa lỗi, cải thiện chức năng.
Video demo sản phẩm : https://youtu.be/J4mfAZkscx0
Ảnh Demo:
![Giao Dien MB](https://drive.google.com/file/d/1H9UkFQltKnHKtkbWOKKa38Ab89xq_HPl/view?usp=sharing)

#Chú Ý:
- Trong chương trình tụi mình có dùng Dev-C++ thư viện Graphics bạn nào chưa cài thì lên Google tìm cách cài thư viện Graphics nhé.
- Đồ án Quản Lý Máy Bay này tụi mình chạy deadline trong 2 tuần do nhiều yếu tố khác quan lẫn chủ quan nên code theo bản năng không tham khảo sách vở.
- Chỉ nên tham khảo phần giao diện phần giải thuật do deadline dí với trình độ lúc đó chưa tốt nên code hơi phèn (chăm đọc giáo trình thầy cho và áp dụng thì điểm sẽ cao hơn).
- Làm đồ án đúng nhất thực tế nhất có thể nếu không điểm sẽ không cao.
- Một số lỗi trong chương trình theo thầy nhận xét:
+ Hủy vé nhưng không xóa vé -> không đặt trên vé đã hủy lại được.
+ Không cho MB thực hiện CB mới nếu trong DSCB chưa hoàn tất hoặc còn vé.
+ Vẫn cho 1 khách hàng mua 2 vé trên 2 CB cùng 1 thời điểm. 

Đề tài:
Quản lý các chuyến bay nội địa thuộc 1 hăng hàng không. Ta tổ chức các danh sau sau: 
- Máy bay : mảng con trỏ có tối đa 300 máy bay. Mỗi máy bay có các thông tin (Số hiệu MB (C15), loại máy bay (C40), số chỗ) ;  Mỗi máy bay có 1 số hiệu duy nhất; số chỗ >=20
- Chuyến bay : danh sách liên kết đơn ( Mã CB (C15),  Ngày giờ khởi hành, sân bay đến , trạng thái, Số hiệu MB, danh sách vé). Mỗi chuyến bay có 1 mã duy nhất; trạng thái chuyến bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé,3: hoàn tất ; danh sách vé cho biết thông tin vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó. Mỗi vé có  số vé  là số thứ tự trên chuyến từ số 1 đến số chỗ .
- Hành khách: cây nhị phân tìm kiếm (Số CMND , Ho, Ten,  Phai)
Chương trình có các chức năng sau: 
a/ Cập nhập danh sách các máy bay (thêm / xóa / hiệu chỉnh)
b/ Cập nhật chuyến bay: cho phép lập chuyến bay mới, hiệu chỉnh ngày giờ khởi hành của chuyến bay , hủy chuyến.
c/Đặt vé: cho phép đặt vé trên 1 chuyến bay; nếu thông tin hành khách chưa có thì tự động cập nhật vào danh sách hành khách, nếu có rồi thì in ra màn hình để kiểm tra. Mỗi vé đều phải ghi nhận số CMND của hành khách; nếu hành khách chưa có số CMND thì yêu cầu nhập thông tin hành khách trước. Trên 1 chuyến bay, mỗi hành khách chỉ được mua 1 vé.
d/ Hủy vé: cho phép hủy vé đã đặt của hành khách.
e/ In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay. Kết xuất:
DANH SÁCH HÀNH KHÁCH THUỘC CHUYẾN BAY ######
Ngày giờ khởi hành: dd/mm/yyyy hh:mm.  Nơi đến : xxxxxxxxxxx

	STT	SỐ VÉ		SỐ CMND	HỌ TÊN	PHÁI
f/ In danh sách các chuyến bay khởi hành trong  ngày dd/mm/yyyy đến nơi XXXX mà còn vé (cho biết cụ thể số lượng các vé còn trống và giờ khởi hành)
g/ In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X. 
h/ Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự  số lượt thực hiện giảm dần. Kết xuất:
	Số hiệu máy bay		Số lượt thực hiện chuyến bay

Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập liệu làm dữ liệu bị sai.