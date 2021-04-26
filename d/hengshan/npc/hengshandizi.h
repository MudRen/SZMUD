// hengshan dizi by firefox
// add songshan job by Xuanyuan
int do_say();
int do_help();
string getroomname(string room);
string getnpcname(string npc);
string do_go();
//void dest();

void init()
{
	::init();
/*	if (query("bang"))
		unconcious();*/
 	set("inquiry", ([
		"����" : (: do_say :),
		"Ԯ��" : (: do_help :),
		"����" : (: do_go :)
	]));

	call_out("dest",1200);
}

int do_help()
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if (me->query("player_id") == ob->query("id") && ob->query("hengshan/job")) {
		message_vision(CYN"$N˵�������������������İɣ�����ʦ�㱻ħ��֮�˷�������л������������\n"NOR,me,ob);
		return 1;
	}
	if (me->query("player_id") == ob->query("id") && ob->query("songshan/job")) {
		if (me->query("bang")==2)
		{
			message_vision(CYN"$N˵��������ɽ����������Ұ�ģ�����֪����ʦ�����ǵ����䡣��\n"NOR,me,ob);
			return 1;
		}
		else
		{
			message_vision(CYN"$N˵������ԭ������ɽ�ɵ����ѣ���ʦ�㱻ħ��֮�˷�������л��λʦ�ֽ�Χ����\n"NOR,me,ob);
			message_vision(CYN"$n˵������ʦ̫Ҳ�����ż���ħ����Ȼ�󵨣�����Ҳ������ʱ�Ӻ�������λʦ�á��������̾���֮�߱��ǡ���\n"NOR,me,ob);
			return 1;
		}
	}
	message_vision("$N��$n˵��������л��ĺ��⣬�ֽ�������Ԯ������\n",me,ob);
	return 1;
}
int do_say()
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if (ob->query("songshan/job")) {
		if (me->query("bang")==2)
		{
			message_vision(CYN"$N˵��������ɽ����������Ұ�ģ�����֪����ʦ�����ǵ����䡣��\n"NOR,me,ob);
			return 1;
		}
		message_vision(CYN"$N˵����������Щ��������ʧ�ٲ��ã���Ȼ���ڸ�����Խ����þã��Ǿ�Խ�����ˡ���\n"NOR,me,ob);
		message_vision(CYN"$n˵������ʦ̫���ģ�����¼Ƚ���ɽ�ɸ�ײ���ˣ���ɽ�ɵ��£���������ɽ�ɵ��£�˵��ôҲ�����ù�����λʦ������ί���Կ�����\n"NOR,me,ob);
		return 1;
	}
	if (me->query("player_id") != ob->query("id") && living(me) && ob->query("hengshan/job")) {
		message_vision(CYN"$N˵������С�������ˡδı�棬���ɸ�֮����ʦ�����䡣��\n"NOR,me,ob);
		return 1;
	}
	message_vision(CYN"$N˵��������ֻ֪��"+getnpcname(query("sister_name"))+"ʦ�㱻���ڸ���Ȫ��"+
		getroomname(query("sister_room"))+"�����һ����Ȱɣ���\n"NOR,me,ob);
	return 1;
}

string getnpcname(string npc)
{
	object npcob;
	npcob=find_object("/d/hengshan/npc/"+npc);
	if (!objectp(npcob) ) npcob=load_object("/d/hengshan/npc/"+npc);
    if (!objectp(npcob)) {
		printf("BUG: Npc %s is missing\n", npcob);
		return 0;
    }
    return npcob->query("name");
}
string getroomname(string room)
{
	object roomob;
	roomob=find_object("/d/quanzhou/"+room);
	if (!objectp(roomob) ) roomob=load_object("/d/quanzhou/"+room);
    if (!objectp(roomob)) {
		printf("BUG: Room %s is missing\n", roomob);
		return 0;
    }
	return roomob->query("short");
}
string do_go()
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if (ob->query("songshan/job") && me->query("bang")==2 && ob->query_temp("bang")==me && !me->query("forceleader")){
		message_vision("$N���ȿ�ʼ����$nһ���ж���\n", me, ob);
		me->set_leader(ob);
		me->set("forceleader",ob);
		ob->add_temp("job_done",1);
		return "���ޣ���ɽ����������Ұ�ģ���ħ�̸��Ӳ��磡��\n\n";
	}
	else if (me->query("player_id") == ob->query("id") && !me->query("bang") && ob->query_temp("blockroad")==2 ){
	    message_vision("$N������ʼ����$nһ���ж���\n", me, ob);
		me->set_leader(ob);
		ob->delete_temp("blockroad");
		return "����л������������\n\n";
	}
	else if (ob->query_temp("blockroad")) 
		return "�ȸ�������������̰ɣ�\n";
//	else if (me->query("bang")) 
//		return "���ܸ��Ƚ⿪�ҵ����Ӱɣ�\n";
	return "��������δı�棬������ҵ���ȥ��\n";
}

void unconcious()
{
	object me, ob;
	me = this_object();
	ob = this_player();
 
	if (objectp(ob = me->query_temp("last_damage_from")) && ob->query_temp("marks/arrestee") == me->query("name") && me->query("bang")!=2 ) {
	message_vision("\n$nͻȻһ������������$N�ļ���Ѩ����\n"NOR, me, ob);
	message_vision(CYN"$N˵�����������������������ɺ϶�Ϊһ������һ�������ɡ����±������ɴӳ����飬���Ը�λ��ð��ħ�̣�ʹ�¶��֣�Ҫ���Һ�ɽ�ɾ������𡣡�\n"NOR, me, ob);
	message_vision(CYN"$N��Ȼ̾��������ɽ��������һ�����ˣ�ȴ��������������������཭����ʿ����ͬ������Ϊ�ѣ����Ǿ��ġ�����������\n"NOR, me, ob);
	message_vision(CYN"\n$n�ɻ��������ӣ���$N�廨���Ѻ��������\n"NOR, me, ob);
	message_vision(CYN"\$n˵�����������źú�Ȱ��齵Ͷ�ϣ���ƫƫ��ִ�������Խ���������п���û��ɽһ���ˡ�\n"NOR, me, ob);
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	me->set("jingli", me->query("max_jingli"));
	me->set("neili", me->query("max_neili"));
	me->set("bang",2);
	ob->set_temp("bang",me);
	ob->delete_temp("marks/arrestee");
	ob->remove_all_killer();
	me->remove_all_killer();
	return;
	}
	::unconcious();
}
void die()
{
	object me, ob;
	me = this_object();
	ob = this_player();
 
	if (objectp(ob = me->query_temp("last_damage_from")) && ob->query_temp("marks/arrestee") == me->query("name") && me->query("bang")!=2 ) {
	message_vision("\n$nͻȻһ������������$N�ļ���Ѩ����\n"NOR, me, ob);
	message_vision(CYN"$N˵�����������������������ɺ϶�Ϊһ������һ�������ɡ����±������ɴӳ����飬���Ը�λ��ð��ħ�̣�ʹ�¶��֣�Ҫ���Һ�ɽ�ɾ������𡣡�\n"NOR, me, ob);
	message_vision(CYN"$N��Ȼ̾��������ɽ��������һ�����ˣ�ȴ��������������������཭����ʿ����ͬ������Ϊ�ѣ����Ǿ��ġ�����������\n"NOR, me, ob);
	message_vision(CYN"\n$n�ɻ��������ӣ���$N�廨���Ѻ��������\n"NOR, me, ob);
	message_vision(CYN"\$n˵�����������źú�Ȱ��齵Ͷ�ϣ���ƫƫ��ִ�������Խ���������п���û��ɽһ���ˡ�\n"NOR, me, ob);
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	me->set("jingli", me->query("max_jingli"));
	me->set("neili", me->query("max_neili"));
	me->set("bang",2);
	ob->set_temp("bang",me);
	ob->delete_temp("marks/arrestee");
	ob->remove_all_killer();
	me->remove_all_killer();
	return;
	}
	::die();
}
void dest()
{
	if (this_object()->query("bang")==1)
		tell_room(environment(this_object()),"һ���������������˳��������廨����"+this_object()->name()+"��չ����������Ծ�����ˡ�\n");
	else if (this_object()->query("bang")==2)
		tell_room(environment(this_object()),""+this_object()->name()+"���ĳ忪Ѩ�������㲻ע������ˡ�\n");
	else {
		command("say ��ɫ����С�����и�ǣ�\n");
		tell_room(environment(this_object()),""+this_object()->name()+"����ææ���뿪�ˡ�\n");
	}
	destruct(this_object());
}