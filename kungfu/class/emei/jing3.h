// Code of ShenZhou
// jing3.h for higher 4 jing shitai

void attempt_apprentice(object ob)
{
        mapping fam;

	if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "������")
        {
        	if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) 
		{
                	command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                	return;
        	}

		if (ob->query("combat_exp") >= 10000 && ob->query("family") )
		{
			command ("say " + RANK_D->query_respect(this_player())
				+ "��" + fam["family_name"] 
				+ "���书���֣����ɿɲ���������");
			return;
		}

                else if ((string)ob->query("class")!="bonze")
		{
			command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�ʩ������ѧ�տ�ȥ�����׼�ʦ�á�");
                        return;
                }

	        else if( (string)ob->query("gender") != "Ů��" )
       		{
              		command ("say �����ӷ𣡴�ʦѽ��ƶ��ɲ��ҿ������Ц����");
			command ("say "+RANK_D->query_respect(ob)+"���ǳ����ˣ���ȥ����Ѱʦ�ɡ�");
                	return;
        	}

                else if ((int)ob->query("shen") < 0) 
		{
                	command("hmm " + ob->query("id"));
                	command("say �Ҷ��������������������ɣ��Ե���Ҫ���ϡ�");
                	command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
                	return;
        	}

		command("say �����ӷ����գ����գ��ڱ������У���Ҫ�ȿ�����ķ𷨡�");
        	ob->set_temp("pending/kao", 1);
		command("say ��Ҫ׼�����ˣ��͸���(nod)�Ұɡ�\n");
        	return; 
	}

        else
	{
        	if ( (string)ob->query("class") != "bonze" ) 
        	{
                	command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
                	command ("say ���������ѧ�����ɵĹ��򣬻���ȥ�����׼�ʦ�ðɡ�");
                	return;
        	}

                else if( (string)ob->query("gender") != "Ů��" )
                {
                        command ("say �����ӷ𣡴�ʦѽ��ƶ��ɲ��ҿ������Ц����");
                	command ("say " +RANK_D->query_respect(ob)+"��Ȼ���˼ң�����ȥ����Ѱʦ��");
			return;
		}
		else if ((int)ob->query("shen") < 0) 
                {
                        command("hmm " + ob->query("id"));
                        command("say �Ҷ��������������������ɣ��Ե���Ҫ���ϡ�");
                	message_vision(
                		"$n����$N˵�������������������ʦ��֪�����Ҳ������㣬��ȥ�ɡ�\n",
                		ob, this_object() );
                        return;
                }

                command("say �����ӷ����գ����գ��ڱ������У���Ҫ�ȿ�����ķ𷨡�");
                ob->set_temp("pending/kao", 1);
                command("say ��Ҫ׼�����ˣ��͸���(nod)�Ұɡ�\n");
                return;

	}
}
