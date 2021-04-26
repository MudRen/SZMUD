// Code of ShenZhou
// /kungfu/class/emei/jing.h for apprentice
// Shan: 96/07/16

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	if (!(ob_fam = ob->query("family"))||ob_fam["family_name"]!= "������") {
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ((string)ob->query("class")!="bonze" && ob_fam["family_name"]=="������")  {
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] == 0 ) {
		command("say �����ӷ�ƶ������������ҵĵ����ˡ�");
		command("recruit " + ob->query("id"));
		ob->set("emei", 1);
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) ) {
		command("say �㲻�Ǹ�"+ob_fam["master_name"]+"���е��裿");
		command("recruit " + ob->query("id"));
		ob->set("emei", 1);
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] ) {
		command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");
		return;
	}

	return;
}

