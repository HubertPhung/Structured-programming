CREATE DATABASE QuanLiSach3;
GO

USE QuanLiSach3;

CREATE TABLE NguoiDung(
	Ten nvarchar(100),
	userName varchar(50),
	pass varchar(20),
	PRIMARY KEY (userName)
);

GO

CREATE PROC proc_dangki
@Ten NVARCHAR(256), @userName VARCHAR (256), @pass VARCHAR (256)

AS
	BEGIN
		insert into	NguoiDung(Ten, userName, pass) values (@Ten, @userName, @pass);
	END;

GO


CREATE TABLE Sach(
	ID int not null IDENTITY(1,1),
	Ten nvarchar(50),
	TacGia nvarchar(50),
	Gia int,
	SoLuong int,
	PRIMARY KEY (ID)
);

GO


CREATE PROC proc_them_sach
@Ten NVARCHAR(256), @TacGia NVARCHAR (256), @Gia INT, @SoLuong INT 

AS
	BEGIN
		insert into	Sach(Ten, TacGia, Gia,SoLuong) values (@Ten, @TacGia, @Gia, @SoLuong);
	END;

GO



CREATE PROC proc_cap_nhat_sach
@ID INT, @Ten NVARCHAR(256), @TacGia NVARCHAR (256), @Gia FLOAT , @SoLuong INT

AS
	BEGIN
		UPDATE Sach
		SET	Ten = @Ten, TacGia = @TacGia, Gia = @Gia ,SoLuong = @SoLuong
		WHERE ID =	@ID
	END;

GO



CREATE TABLE HoaDon (
    DonHangID int not null IDENTITY(1,1),
    NguoiDung_UserName varchar(50),
	ThoiGian datetime,
	TongTien int,
    FOREIGN KEY (NguoiDung_UserName) REFERENCES NguoiDung(userName),
	PRIMARY KEY(DonHangID)
);

GO

CREATE PROC proc_hoa_don
@NguoiDung_UserName varchar(50), @ThoiGian datetime, @TongTien int

AS
	BEGIN
		insert into	HoaDon(NguoiDung_UserName,ThoiGian, TongTien) values (@NguoiDung_UserName,@ThoiGian, @TongTien);
		SELECT SCOPE_IDENTITY() AS DonHangID;
	END;

GO



CREATE TABLE ChiTietHoaDon (
    ChiTietDonHangID int PRIMARY KEY not null IDENTITY(1,1),
    DonHangID int,
    SachID int,
    SoLuong int,
    TongTien int,
    FOREIGN KEY (DonHangID) REFERENCES HoaDon(DonHangID),
    FOREIGN KEY (SachID) REFERENCES Sach(ID)
);
GO


--Sach
INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'White Clover Markets', N'Karl Jablonski', 75, 55);
INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'Wilman Kala', N'Matti Karttunen', 50, 99);

INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'Wolski', N'Zbyszek', 350, 80);

INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'Cardinal', N'Tom B. Erichsen', 109, 80);

INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'stoicism', N'Seneca', 100, 120);
INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'Specified ', N'Sesokeca', 100, 89);
INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'PPHoong', N'SeKKca', 145, 156);
INSERT INTO Sach(Ten, TacGia, Gia, SoLuong)
OUTPUT inserted.ID VALUES (N'LOL', N'Kemmmm', 107, 120);


--User
INSERT INTO NguoiDung(Ten, userName, pass) VALUES (N'Tanh', N'tan123', N'123');

INSERT INTO NguoiDung(Ten, userName, pass) VALUES (N'Bo', N'bo123', N'456');

INSERT INTO NguoiDung(Ten, userName, pass) VALUES (N'Anh', N'anh123', N'789');
