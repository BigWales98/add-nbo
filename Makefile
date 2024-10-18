# 컴파일러와 옵션
CC = gcc
CFLAGS = -Wall -g

# 타겟 실행 파일
TARGET = add-nbo

# 소스 파일
SRC = add-nbo.c

# 빌드 규칙
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# 실행 파일 삭제
clean:
	rm -f $(TARGET)

