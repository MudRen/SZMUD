// �����ݡ���
// Yujie Sep 30

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        string top_id;
        int data;

        if(!arg || arg =="") {
        	write(TOPTEN_D->query_min_limit());
        	return 1;
        }
        
        if(sscanf(arg,"%s %d",top_id,data)!=2)
             return help();

        if(TOPTEN_D->set_min_limit(top_id,data))
        	write("ok.\n");
        else write("����ʧ�ܡ�\n");
        return 1;
}

int help()
{
        write("\nָ���ʽ : tset <����> <��ֵ>\n");
	write(	"��������������ý������а�����Ҫ����Сֵ��\n"+
		"���磬tset exp 10000�������exp���а�����Ҫ��10000�㾭�顣\n");
		
	return 1;
}
