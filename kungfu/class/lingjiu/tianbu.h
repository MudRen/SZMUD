//Cracked by Kafei
// tianbu.h for lingjiu master
// By Xuanyuan 11/18/2001

#include <ansi.h>

void attempt_apprentice(object ob)
{
        mapping fam;

        if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "���չ�") {

		if(ob->query("gender") != "Ů��") {
                	command("say ���չ�ֻ��Ů���ӣ�"+RANK_D->query_respect(ob)+"������ذɡ�");
                return;
                }

        	if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 )  {
               		command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                	return;
        	}
			
                if (ob->query("family/family_name") != "���չ�" && ob->query("combat_exp") >= 10000 ) {
                        command ("say " + RANK_D->query_respect(this_player())
                                + "��" + fam["family_name"]  + "���书���֣����ɿɲ���������");
                        return;
                }

                if ((string)ob->query("class") =="bonze") {
			if ((string)ob->query("gender") == "Ů��")  {
				command("hmm " + ob->query("id"));
				command("say " +RANK_D->query_respect(ob) +"���ǳ����ˣ�����ȥ����ɽ���ǵ�ʦ̫�ǰɡ�");
                		return;
			}
			else {
                                command("say " +RANK_D->query_respect(ob) +"���ǳ����ˣ���ȥ����Ѱʦ�ɡ�");
                        	return;
                	}
		}

		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say �����չ��䲻���������ɣ���Ҳ�����ڼ�а֮��Ϊ�顣");
                	command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
        		return;
		}

		command("say �ðɣ��Ҿ��������ˡ�ϣ����������������������չ�������"); 
        	command("recruit " + ob->query("id"));
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
                		command("say �ҿ��㻹��ȥ����ɽ�ɡ�");
                		return;
			}
		}

		command("say �ðɣ��Ҿ��������ˡ�ϣ����������������������չ�������"); 
		command("recruit " + ob->query("id"));
	}
	return;
}
