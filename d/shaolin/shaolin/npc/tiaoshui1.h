// Code of ShenZhou
//xiaojian May25,2000

string ask_tiaoshui()
{
	object me, ob;
	string event;
	string fam;
	int time;
	mapping my_fam;
	me = this_player();
	ob = this_object();
	event = NATURE_D->outdoor_room_event();
	fam = me->query("family/family_name");
	my_fam = me->query("family");
	if (!fam || fam != "������")
		return "�����ӷ�,��λʩ�����������µģ�ƶɮ�ɲ����Ͷ���ݡ�";
	//buwu ȡ�� tiaoshui job �� exp ���ƣ�����ת��Ϊһ�� 1.2k/hour �� robot job��
	//if (me->query("combat_exp") > 500000)
	//	return "��λ"+RANK_D->query_respect(ob)+"�Ѿ��Ǹ����ˣ������������ִֻ���! ";
	
	/*if (event == "event_night" || event == "event_midnight")
		return "�����ӷ�,���µ�ɽ��ҹ����,"+RANK_D->query_respect(me)+ "���ǵ����������ɡ�";*/
	if (me->query("shaolin/job_asked"))
		return RANK_D->query_respect(me)+ "�����ʹ�������ô��������͵��? ";
	if(me->query_condition("ts_pending"))
		return "Ŀǰ���Ҳ���ʲô�������ɣ���ȵ������ɡ�";
	
	command("nod");
	command("say ���������ã�������������ÿ����Ҫ���ˮ����ȥɽ����Щˮ��! \n");
	command("say ��ȥ���շ�ɮҪ����ˮ�Ĺ��ߡ�\n");
	me->set("shaolin/job_asked",1);
	time = 150 + random(50);
	me->apply_condition( "tiaoshui", time );
	return "��ȥ��أ�ֱ�Ӱ�ˮ�͵�������";

}
string ask_abandon()
{
	object me, ob;
	int busy;
	object *inv;
	int i;
	ob = this_player();
	me = this_object();
	inv = all_inventory(me);
	if (!ob->query("shaolin/job_asked"))
		return "�����ڲ�û����������ѽ��";
	command("disapp "+ob->query("id"));
	command("say ����ô��С�¶��첻�ˣ�������ôΪ�����³���ѽ? \n");
	ob->delete("shaolin/job_asked");
	ob->delete("shaolin/tool_assigned");
	if(ob->query_condition("tiaoshui"))
          ob->clear_one_condition("tiaoshui");
	for (i = 0; i <sizeof(inv);i++){
		if (inv[i]->query("id") == "shui tong")
			destruct("shui tong");
	}
    busy = 20+random(8);
	ob->apply_condition("ts_pending", busy );
	return "��ȥ�ú÷�˼һ�°ɡ�";
}

