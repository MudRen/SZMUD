// Code of ShenZhou
// jing1.h for the 4 jing shitai who don't recruit

void attempt_apprentice(object ob)
{
        mapping fam;

	if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "������")
        {
                if ((string)ob->query("class")!="bonze")
		{
			command ("say �����ӷ�ƶ�᲻�յ��ӡ�ʩ������ѧ�տ�ȥ�����׼�ʦ�á�");
                        return;
                }

	        else if( (string)ob->query("gender") != "Ů��" )
       		{
              		command ("say �����ӷ�ƶ�᲻�յ��ӡ�"+RANK_D->query_respect(ob)+"���ǳ����ˣ���ȥ����Ѱʦ�ɡ�");
                	return;
        	}

        	command("say �����ӷ�ƶ�᲻�յ��ӡ�"+RANK_D->query_respect(ob)+"ȥ����ʦ��ɡ�");
		return;
	}

        else
	{
               	command ("say �����ӷ�ƶ�᲻�յ��ӡ�");
               	command ("say ���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�");
               	return;
       	}
}
