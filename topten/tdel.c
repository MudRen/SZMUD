// �����硤���μǣ���������WUHEE WIZ.GROUP
// misu

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        string top_id, id;

        if(!arg || sscanf(arg,"%s %s",top_id,id)!=2)
             return help();

        TOPTEN_D->topten_del(id, top_id);
        write("ok.\n");
        return 1;
}

int help()
{
        write("\nָ���ʽ : tdel <����> <���ID>\n");
	
	return 1;
}
