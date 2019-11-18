//方法一：

CMyString& CMyString::operator = (const CMyString &str)
{
  if (this == &str)
      return *this;
  delete [] m_pData;
  m_pData = nullptr;
  
  m_pData = new char[strlen(str.m_pData)+1];
  strcpy(m_pData,str.m_pData);
  
  return *this;
}


// 方法二：考虑异常安全性的解法：
CMyString& CMyString::operator = (const CMyString &str)
{
  if(this!=str)
  {
      CMyString strTemp(str);
      
      char* pTemp = strTemp.m_pData;
      strTemp.m_pData = m_pData;
      m_pData = pTemp;
  }
  return *this;
}
