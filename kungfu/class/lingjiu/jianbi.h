//Cracked by Kafei
// jianbi.h for lingjiu master
// By Xuanyuan 11/18/2001

#include <ansi.h>

void attempt_apprentice(object ob)
{
        	mapping fam = ob->query("family");

		if (ob->query("gender") != "Ů��") {
			command("say ��ֻ��Ů���ӣ�"+RANK_D->query_respect(ob)+"��ذɡ�");
			return; 
		}
		if (!fam || fam["family_name"] != "���չ�"){
                	command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                	return;
                }
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
		if((int)ob->query_skill("force", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                	return;
                }  
		if((int)ob->query_skill("bahuang-gong", 1) < 80) {
			command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
                	return;
                }  
		if((int)ob->query_skill("dodge", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("yueying-wubu", 1) < 80 && (int)ob->query_skill("lingbo-weibu", 1) < 80 ) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("sword", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("tianyu-qijian", 1) < 80) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                	return;
                }
		if (ob->query_con() < 20) {
			command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
			return;
		}
		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say �����չ��䲻���������ɣ���Ҳ�����ڼ�а֮��Ϊ�顣");
                	command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
        		return;
		}
		command("say �ðɣ��Ҿ��������ˡ�ϣ����������������������չ�������"); 
        	command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
}
