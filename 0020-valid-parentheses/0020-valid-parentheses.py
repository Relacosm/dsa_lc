class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        dict={")":"(","]":"[","}":"{"}
        for c in s:
            if c in dict:
                if st and st[-1]==dict[c]:
                    st.pop()
                else:
                    return False
            else:
                st.append(c)
        return True if not st else False 