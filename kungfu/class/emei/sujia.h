// Code of ShenZhou
// sujia.h for sujia master

#include <ansi.h>

void attempt_apprentice(object ob)
{
        mapping fam;

        if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "������") {

        	if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 )  {
               		command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                	return;
        	}
			
                if (ob->query("combat_exp") >= 10000 && ob->query("family") ) {
                        command ("say " + RANK_D->query_respect(this_player())
                                + "��" + fam["family_name"]  + "���书���֣����ɿɲ���������");
                        return;
                }

                if ((string)ob->query("class") =="bonze") {
			if ((string)ob->query("gender") == "Ů��")  {
				command("hmm " + ob->query("id"));
				command("say " +RANK_D->query_respect(ob) +"���ǳ����ˣ�����ȥ��ɽ�����������Ҿ��ֱ�ʦ��ɡ�");
                		return;
			}
			else {
                                command("say " +RANK_D->query_respect(ob) +"���ǳ����ˣ���ȥ����Ѱʦ�ɡ�");
                        	return;
                	}
		}

		if ((int)ob->query("shen") < -10)  {
                        command("hmm " + ob->query("id"));
                        command("say �Ҷ��������������������ɣ��Ե���Ҫ���ϡ�");
                	command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
        		return;
		}

		if ((string)ob->query("gender") != "Ů��")  { 
                        command("hmm " + ob->query("id"));
                        command("say ���Ƕ����ɵĹ���Ƚ��ʺ�Ů������ϰ��"); 
                        command("say ��Ȼ" +RANK_D->query_respect(this_player()) +  "ҪѧЩǿ����ı��죬������������ɡ�");
                	command("recruit " + ob->query("id"));
        		ob->set("emei", 1);
			if (!ob->query("MKS_emei")) 
			    ob->set("MKS_emei", ob->query("MKS"));
//			ob->set("emei_shen", ob->query("shen"));
                	return;
        	}

		command("say �ðɣ��Ҿ��������ˡ�ϣ����������������������Ҿ�������"); 
        	command("recruit " + ob->query("id"));
		if (!ob->query("MKS_emei")) 
		    ob->set("MKS_emei", ob->query("MKS"));
        	ob->set("emei", 1);
//		ob->set("emei_shen", ob->query("shen"));
	}

	else {
        	if ((string)ob->query("class") == "bonze")  {
			if ((string)ob->query("gender") != "Ů��" ) {
				message_vision( "$n����$N˵�������Ȼ���˼ң����������������У�\n", ob, this_object() );
                		command("say �ҿ��㲻��ȥ������Ѱʦ�ɡ�\n");
                		return;
        		}
			else {
                                message_vision( "$n����$N˵��������˼ң����������������У�\n", ob, this_object() );
                		command("say �ҿ��㻹�ǻ���ȥ�ɡ�");
                		return;
			}
		}

/*
		if ((int)ob->query("shen") < (int)ob->query("emei_shen"))  {
        		command("hmm " + ob->query("id"));
        		command("say �Ҷ��������������������ɣ��Ե���Ҫ���ϡ�");
        		message_vision( "$n����$N˵�������������������ʦ��֪�����Ҳ������㣬��ȥ�ɡ�\n", ob, this_object() );
        		return;
		}
*/
		if ((string)ob->query("gender") != "Ů��" ) { 
                	command("hmm " + ob->query("id"));
                	command("say ���Ƕ����ɵĹ���Ƚ��ʺ�Ů������ϰ��"); 
                	command("say ��Ȼ" +RANK_D->query_respect(this_player()) +  "ҪѧЩǿ����ı��죬������������ɡ�");
                	command("recruit " + ob->query("id"));
			ob->set("emei", 1);
//			ob->set("emei_shen", ob->query("shen"));
                	return;
        	}

		command("say �ðɣ��Ҿ��������ˡ�ϣ����������������������Ҿ�������"); 
		command("recruit " + ob->query("id"));
		ob->set("emei", 1);
//		ob->set("emei_shen", ob->query("shen"));
	}
	return;
}
