```c++
class CMyString {
public:
     CMyString(char *pData = nullptr);
     //拷贝构造函数
     //因为是新建立的变量，所以不用考虑自赋值，不用考虑释放旧值
     CMyString(const CMyString &);
     ~CMyString();
     CMyString &operator = (const CMyString &str);
     char *getData();
private:
     char *m_pData;
};
```
