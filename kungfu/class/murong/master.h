// Code of ShenZhou
// arthurgu 1999.9
//Modify by Sure 2000.5

void attempt_apprentice(object ob)
{
       mapping fam;
       string gsmr;
        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="Ů��")
                        command ("say �����벻���������ˣ�ʦ̫��ذɡ�");
                return;
        }

          if( ob->query("family/family_name") != "����Ľ��" && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                        +ob->query("family/family_name")+"���֣�������ɲ���������");
                return;
        }
		  if ((string)ob->query("gender") == "����" && (int)ob->query_skill("pixie-jian",1) > 50 ) {
                command("say " + RANK_D->query_respect(ob) + "�Ƕ������ˣ�ˡ�Ҳ������㡣");
                return;
        }
		  if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                return;
        }
		  if ((string)ob->query("family/family_name") == "ȫ���" ) {
                command("say �����벻�ŷ���̣���λ���ֻ�����������ɡ�");
                return;
        }
		  if ((string)ob->query("family/family_name") == "�䵱��" ) {
                command("say ������ذɣ������벻����������");
                return;
        }
		  if ((string)ob->query("family/family_name") == "������" ) {
                command("say �Ҽҹ�����޶�������������");
                return;
        }
		  if ((string)ob->query("family/family_name") == "������" ) {
                command("say �Ҽҹ�������յ��ӣ����߰ɡ�");
                return;
        }
		  if ((string)ob->query("family/family_name") == "��ɽ��" ) {
                command("say ��ɽ�����������ɣ������벻����������");
                return;
        }
		  if ((string)ob->query("family/family_name") == "Ѫ����" ) {
                command("say �����벻��Ѫ���ŵ������������������");
                return;
        }
		  if ((string)ob->query("family/family_name") == "�һ���" ) {
                command("say ��а��ҩʦ��������ţ���λ" + RANK_D->query_respect(ob) + "Ϊ����Ͷ���������أ�");
                return;
        }
	      if ((string)ob->query("family/family_name") == "����" ) {
                command("say ��������������۰�һ������λ" + RANK_D->query_respect(ob) + "�ο����ٲ�����");
                return;
        }
	{
        	if (ob->query("family/family_name")!="����Ľ��") {
        	if (ob->query("gender")=="Ů��") gsmr="ʹŮ";
	        else  gsmr = "�ж�";
        	command("say �ðɣ��Ҿ�����������" + gsmr + "�ɡ�");
	        command("recruit " + ob->query("id"));
        	ob->set("title","����Ľ�� ������"+gsmr);
	        ob->set("mr/rank", 1);
        	return;
   
                                                           }
   }
