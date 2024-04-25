# AIR BATTLE 
 ## INTRODUCTION
- Họ và tên: 'Đặng Quang Huy - K68J - UET'
- Mã sinh viên: 23020671
- Bài tập lớn: AIR BATTLE (INT2215_52 - Lập trình nâng cao)

## DISCRIPTION
### GAME DISCRIPTION AND INSTRUCTION :
- AIR BATTLE là một thể loại game Shoot 'em up (Shmup), người chơi sẽ điều khiển một đối tượng chính là một máy bay để tiêu diệt hết
  các máy bay và trùm cuối của quân địch. Bên cạnh đó, game còn có thêm điều kiện phụ liên quan đến thời gian và điểm số để tăng thêm sự gay cấn
  và tạo thử thách cho người chơi. Trên màn hình game cũng sẽ xuất hiện ngẫu nhiên những vật phẩm bổ trợ, người chơi khi ăn được một lượng nhất
  định sẽ nhận thêm 1 mạng sống.
 - Mối lần chơi , game sẽ random background tạo sự đa dạng , thích thú cho người chơi.
- Game có đầy đủ các chức năng hỗ trợ người chơi , thoát game , xem mô tả cách chơi, sử dụng phím esc để dừng game, chơi lại ...
- Có âm thanh nền phát trong suốt lúc chơi và các âm thanh về bắn đạn, vụ nổ gây cảm giác kích thích, hứng thú cho người chơi.
- AIR BATTLE chắc chắn sẽ không khiến cho người chơi phải thất vọng với những tính năng, đồ hoạ cực kì hấp dẫn, sinh động.
## CONTROL :
| **KEYS** | ** FUNCTION** |
|:--------:|:-------------:|
|     W    |       UP      |
|     S    |      DOWN     |
|     A    |      LEFT     |
|     D    |     RIGHT     |
|     K    |  LASER BULLET |
|     L    |  DART BULLET  |

![a1](https://github.com/HuyDang05/My_Game/assets/161727773/e4c42436-e309-45ef-a8c0-5f8ef5c2c982)
![a2](https://github.com/HuyDang05/My_Game/assets/161727773/4fe7d57f-9f92-477e-868c-422727b8e848)
![a3](https://github.com/HuyDang05/My_Game/assets/161727773/e76c53bd-e8e4-4b1b-9c4e-5cef3052927c)
![a6](https://github.com/HuyDang05/My_Game/assets/161727773/96d1f7c4-8689-414f-9804-e42be8e59a7a)
![a4](https://github.com/HuyDang05/My_Game/assets/161727773/1cd84857-1f52-4714-ac55-83e86fa74863)
![a5](https://github.com/HuyDang05/My_Game/assets/161727773/ced6f00c-ffa3-4f92-8205-31781ac45e6d)


## SEE ALSO :
### Các kỹ thuật sử dụng :
- Thư viện SDL2.0, ngôn ngữ C++, IDE : Visual Studio Code.
- Sử dụng kỹ thuật tách file cpp và file header để dễ quản lý chương trình
- Tạo đối tượng đa dạng : nhân vật chính, máy bay địch, máy bay boss địch, vật phẩm hỗ trợ, đạn bắn, text và HP của nhân vật chính.
- Dùng các kiến thức toán học để xử lý va chạm giữa các đối tượng : đạn của nhân vật chính với địch, nhân vật chính với vật phẩm hỗ trợ, ...
- Xử lý thời gian, điểm số thao tác chuột và bàn phím, âm thanh, hình ảnh, chữ và random background khi vào chơi.
- Tạo menu giúp game chân thực hơn : menu bắt đầu, menu hướng dẫn , menu thắng, menu thua.
- Xứ lý việc bắn đạn, di chuyển ngang màn hình cho threat, khi bị tiêu diệt, threat sẽ được đặt vị trí ngẫu nhiên để xuất hiện trên màn hình.
- Đối tượng Boss sẽ kế thừa từ đối tượng threat nhưng sẽ có tính nắng mới : máu nhiều hơn, cách di chuyển khác và nhanh hơn, đạn bắn nhanh hơn,...
   
### Nguồn tham khảo :

- Cách cài đặt SDL2.0 trên Visual Studio Code: tham khảo trên reddit, stack overflow và Lazy'Foo.
- Cách sử dụng thư viện SDL2.0, quản lý chương trình: Thảo khảo trên Lazy'Foo và các video của cô Nguyễn Thị Minh Châu,
 stack overflow, kênh youtube: Let's Make Games, Madsycode, Phát Triển Phần Mềm 123 A-Z.
- Hình ảnh: tìm kiếm trên google và một số hình đơn giản tự design.
- Âm thanh: Tự tra trên google, pixabay.com
- Logic chính của game: tham khảo kênh youtube : Phát Triển Phần Mềm 123 A-Z và tự phát triển thêm ở các vật phẩm bổ trợ, đối tượng boss.
menu, điều kiện phụ về thời gian và điểm số.

## CONCLUSION :
- Em thấy mình đã cải thiện được rất nhiều kỹ năng trong việc tư duy logic, xử lý va chạm, viết code. 
- Khả năng sáng tạo, lên ý tưởng, các kỹ năng về chỉnh sửa hình ảnh , âm thanh.
- Học được cách setup môi trường, sử dụng thư viện ngoài.
- Chương trình rất dễ để refactor cũng như update tính năng.
- Học được cách thêm và sắp xếp các khối câu lệnh để chương trình chạy mượt mà, hợp lý, cách clean, tối ưu code và sử lý các mạch logic chính của game.
- Biết thêm về thư viện SDL2 : cách sử dụng, các hàm để xử lý hình ảnh, âm thanh , chữ.
### Hướng phát triển 
- Cập nhật tính năng bảng xếp hạng, sau mỗi lần chơi người chơi sẽ được nhập tên để lưu lại kết quả chơi của mình.
- Thêm nhiều loại vật phẩm hỗ trợ có tính năng khác nhau.
- Thêm các chướng ngại vật và bom để tạo thử thách cho người chơi.
- Thêm menu chọn độ khó  để người chơi có thể chọn tốc độ và số lượng địch tuỳ thích, phù hợp với khả năng chơi của mình.
- Thêm chế độ 2 người chơi với nhau hoặc 2 người chơi với máy.
- 
  
