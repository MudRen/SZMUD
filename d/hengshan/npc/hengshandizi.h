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
		"下落" : (: do_say :),
		"援助" : (: do_help :),
		"动身" : (: do_go :)
	]));

	call_out("dest",1200);
}

int do_help()
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if (me->query("player_id") == ob->query("id") && ob->query("hengshan/job")) {
		message_vision(CYN"$N说道：“是掌门请你来的吧，我派师姐被魔教之人伏击，多谢大侠相助。”\n"NOR,me,ob);
		return 1;
	}
	if (me->query("player_id") == ob->query("id") && ob->query("songshan/job")) {
		if (me->query("bang")==2)
		{
			message_vision(CYN"$N说道：“嵩山派这样狼子野心，休想知道我师姐妹们的下落。”\n"NOR,me,ob);
			return 1;
		}
		else
		{
			message_vision(CYN"$N说道：“原来是嵩山派的朋友，派师姐被魔教之人伏击，多谢这位师兄解围。”\n"NOR,me,ob);
			message_vision(CYN"$n说道：“师太也不用着急，魔教虽然大胆，料来也不敢立时加害贵派诸位师妹。咱们详商救人之策便是。”\n"NOR,me,ob);
			return 1;
		}
	}
	message_vision("$N对$n说道：“多谢你的好意，现今我无需援助！”\n",me,ob);
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
			message_vision(CYN"$N说道：“嵩山派这样狼子野心，休想知道我师姐妹们的下落。”\n"NOR,me,ob);
			return 1;
		}
		message_vision(CYN"$N说道：“我这些姐妹们们失踪不久，定然便在附近，越耽误得久，那就越难找了。”\n"NOR,me,ob);
		message_vision(CYN"$n说道：“师太放心，这件事既教嵩山派给撞上了，恒山派的事，便是我嵩山派的事，说甚么也不能让贵派诸位师妹们受委屈吃亏。”\n"NOR,me,ob);
		return 1;
	}
	if (me->query("player_id") != ob->query("id") && living(me) && ob->query("hengshan/job")) {
		message_vision(CYN"$N说道：“小尼与大侠恕未谋面，怎可告之我派师姐下落。”\n"NOR,me,ob);
		return 1;
	}
	message_vision(CYN"$N说道：“我只知道"+getnpcname(query("sister_name"))+"师姐被困在福建泉州"+
		getroomname(query("sister_room"))+"请大侠一并解救吧！”\n"NOR,me,ob);
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
		message_vision("$N被迫开始跟随$n一起行动。\n", me, ob);
		me->set_leader(ob);
		me->set("forceleader",ob);
		ob->add_temp("job_done",1);
		return "“呸，嵩山派这样狼子野心，比魔教更加不如！”\n\n";
	}
	else if (me->query("player_id") == ob->query("id") && !me->query("bang") && ob->query_temp("blockroad")==2 ){
	    message_vision("$N决定开始跟随$n一起行动。\n", me, ob);
		me->set_leader(ob);
		ob->delete_temp("blockroad");
		return "“多谢大侠相助！”\n\n";
	}
	else if (ob->query_temp("blockroad")) 
		return "先赶走蒙面人再起程吧！\n";
//	else if (me->query("bang")) 
//		return "你总该先解开我的绳子吧！\n";
	return "我与你素未谋面，你想带我到哪去？\n";
}

void unconcious()
{
	object me, ob;
	me = this_object();
	ob = this_player();
 
	if (objectp(ob = me->query_temp("last_damage_from")) && ob->query_temp("marks/arrestee") == me->query("name") && me->query("bang")!=2 ) {
	message_vision("\n$n突然一个近身，点中了$N的几处穴道！\n"NOR, me, ob);
	message_vision(CYN"$N说道：“贵派意欲将五岳剑派合而为一，并成一个五岳派。此事本来尽可从长计议，何以各位竟冒充魔教，痛下毒手，要将我恒山派尽数诛灭。”\n"NOR, me, ob);
	message_vision(CYN"$N惨然叹道：“嵩山派左掌门一代高人，却收罗了许多左道……这许多江湖异士，和同道中人为难，真是居心……唉……”\n"NOR, me, ob);
	message_vision(CYN"\n$n由怀里抽出绳子，将$N五花大绑押了起来。\n"NOR, me, ob);
	message_vision(CYN"\$n说道：“左掌门好好劝你归降投诚，你偏偏固执不听，自今而后，武林中可再没恒山一派了。\n"NOR, me, ob);
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
	message_vision("\n$n突然一个近身，点中了$N的几处穴道！\n"NOR, me, ob);
	message_vision(CYN"$N说道：“贵派意欲将五岳剑派合而为一，并成一个五岳派。此事本来尽可从长计议，何以各位竟冒充魔教，痛下毒手，要将我恒山派尽数诛灭。”\n"NOR, me, ob);
	message_vision(CYN"$N惨然叹道：“嵩山派左掌门一代高人，却收罗了许多左道……这许多江湖异士，和同道中人为难，真是居心……唉……”\n"NOR, me, ob);
	message_vision(CYN"\n$n由怀里抽出绳子，将$N五花大绑押了起来。\n"NOR, me, ob);
	message_vision(CYN"\$n说道：“左掌门好好劝你归降投诚，你偏偏固执不听，自今而后，武林中可再没恒山一派了。\n"NOR, me, ob);
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
		tell_room(environment(this_object()),"一个黑衣蒙面人跳了出，扛起五花大绑的"+this_object()->name()+"，展开身法几个跳跃不见了。\n");
	else if (this_object()->query("bang")==2)
		tell_room(environment(this_object()),""+this_object()->name()+"悄悄冲开穴道，趁你不注意溜掉了。\n");
	else {
		command("say 天色已晚，小尼先行告辞！\n");
		tell_room(environment(this_object()),""+this_object()->name()+"急急忙忙地离开了。\n");
	}
	destruct(this_object());
}