// Code of ShenZhou
void attempt_apprentice(object ob)
{
	mapping fam;
    string dldj;

	if (ob->query("family/family_name")!="����μ�") {
		command("shake "+ob->query("id"));
		command("say ������Ͷ�����Ϊ�����������㽭�����񣬲�����ͽ�ˡ�");
        return;
	}

    command ("look "+ob->query("id"));

	if (ob->query("shen")<0) {
		command("say �������ݲ������������С�ˣ�");
		return;
	}

	command("hehehe "+getuid(ob));
	command("say ���ұ���ͬ�����£�������ѧЩ����Ȼû���⡣");
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
	return;
}

