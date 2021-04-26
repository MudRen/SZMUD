//Cracked by Roath

#include <ansi.h>
inherit NPC;
string ask_job();
string ask_suicong();
string ask_yaopai();
int do_ling(string);

#include "/d/beijing/beijing_defs.h"
#include "/d/beijing/job_info.h"
void set_shiwei_status(int);

string *Robber_Name = ({
	"����","ɽ����","·��","ɽ��","ë��","կ��","���"
	});
string *Biaohuo_Name = ({
	"����","���","����","��ʯ","����","����","����"
	});

string ask_abandon();
void assign_biaotou(object me, object partner);
void setup_skill(object me,object obj);
private int is_suitable(object victim, object killer);
private int is_suitable_rob(object victim, object killer);
string QueryDest(object obj);
int assign_rob(object me);

void create()
{
    set_name("��¡", ({
	    "duo long", "duo",
    }));
    set("title", "�����ܹ�");
    set("long",
	"��Ϊ�����ܹܣ���¡���ܻ������ء�\n"
	"���־������񶼴���������ɡ�\n"
    );


    set("gender", "����");
    set("age", 35);
    setup();

    set_shiwei_status(180);

    set("inquiry", ([
	"job" : (: ask_job :),
	"����" : (: ask_job :),
	"����" : "����㵽����ȥ��������ɡ�",
	"promote" : "����㵽����ȥ��������ɡ�",
	"����" : "����㵽����ȥ��������ɡ�",
	"���" : (: ask_suicong :),
	"suicong" : (: ask_suicong :),
	"here" : "����������Ӫ������������",
	"����" : (: ask_yaopai :),
	"yaopai" : (: ask_yaopai :),
		"abandon" : (: ask_abandon:),
		"����" : (: ask_abandon:),
    ]));
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);

	add_action("do_jobwith", "jobwith");
    add_action("do_ling", "ling");
	if( interactive(ob = this_player()) && !is_fighting())
	{
		//remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int bonus,old_pot;
	string *skname;
	mapping skills;
	int i;

	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("biao/bonus") )
	{
		bonus = ob->query("biao/bonus");
		message_vision( HIG"$N����$nЦ����$n�ɵĺã����ǳ�͢ȫ�����������˲š�\n\n"NOR,this_object(),ob);
		command( "thumb "+ob->query("id") );
		ob->delete("biao");
		ob->add("combat_exp", bonus );
		old_pot = ob->query("potential");
		if(bonus>360)bonus=360;
		ob->add("potential", bonus );
		ob->remove_all_killer();
		if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
		ob->add("biaoju/succeed",1);
		ob->add("bingbu/job_cur", 3);
		if( ob->query("potential") > ob->query("max_potential") ) ob->set("potential",ob->query("max_potential") );
		add_temp("biao", -1);
		log_file("/test/BiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")�ڹٸ����ڻ��" + bonus + "�����"+ (ob->query("potential")-old_pot) + "Ǳ��\n" );
	}
	if( ob->query("master_name") == "��������" || ob->query("master_name") == "�ױ�")
	{
		command( "say ���ٲ���ͽ�ܣ���������ʦ��");
		message_vision("\n$N����$n˵�����ӽ�������������ʦ��\n\n", this_object(), ob);
		ob->delete("family");
		ob->delete("title");
		ob->delete("master_id");
		ob->delete("master_name");
		ob->set("score", 0);
		skills = ob->query_skills();
		if( mapp(skills) )
		{
			skname = keys(skills);
			for(i=0; i<sizeof(skname); i++) skills[skname[i]] /= 2;
		}
	}
}

int sync_mizheng(object player)
{
    object mizheng;

    // fix test players
    mizheng = HELPER->find_mizheng();
    if (mizheng->player_rank(player->query("id")) == -1) {
	message_vision("$N�ɻ�Ŀ���$nһ�ۣ�����ô��������ͷ�εģ�\n",
	    this_object(), player);
	mizheng->normalize(player);
        return 1;
    }
    return 0;
}

string ask_yaopai ()
{
    object player = this_player(), me = this_object();
    object *inv, yaopai;
    int i;

    if (! IS_SHIWEI(player)) 
	return "���ֲ���������Ҫʲô���ƣ�";

    if (sync_mizheng(player)) return "�����µ��������Ƕ�ȥ�Ǽǰɡ�";

    inv = all_inventory(player);
    for (i=0; i<sizeof(inv)-1; i++){
	if (base_name(inv[i]) == "/d/beijing/obj/yaopai") 
	    return "�㲻������������";
    }
    yaopai = new ("/d/beijing/obj/yaopai");
    yaopai->move(player);
    message_vision("$N��$nһ���������ơ�\n", me, player);
    return "С�ĵ㣬���ϸ㶪�ˡ�";
}

string ask_job()
{
    object player = this_player(), me = this_object();
	object biaoche;

    int i, shichen=HELPER->shichen(), penalty;

    if (!IS_SHIWEI(player)) 
        return "���ȵ�����Ͷ���ɡ�";
    if (sync_mizheng(player)) return "�����µ��������Ƕ�ȥ�Ǽǰɡ�";

    if (player->query_temp("current_job")) {
	if (SHIWEI_LEVEL(player)<4) {
	    return "�Ҳ��Ǹ���������ȥ"+
		    player->query_temp("current_job")+"���Űɡ�";
	}
  	return "�Ҳ��Ǹ���������?";
    }

    switch (SHIWEI_LEVEL(player)) {
    case 0:	// first level
	if (HELPER->is_sunrise() < 0) 
	    return "���ڻ�û���㵱���ʱ���ء�";
	if (HELPER->is_sunrise() > 0) 
	    return "������î��ʱ���Ѿ����ˣ������������ɡ�";
	i = random(sizeof(outer_gate_name));
	player->set_temp("current_job", outer_gate_name[i]);
	return "���ȥ"+outer_gate_name[i]+"���� (guard) �ɡ�";
    case 1:	// second level
	if (HELPER->is_sunset() < 0) 
	    return "�컹�����أ��Ȼ���������Ϸ����";
	if (HELPER->is_sunset() > 0) 
	    return "�춼�����������������˵�ɡ�";
	i = random(sizeof(outer_gate_name));
	player->set_temp("current_job", outer_gate_name[i]);
	return "���ȥ"+outer_gate_name[i]+"���� (guard) �ɡ�";
    case 2:	// third level
	if (HELPER->is_sunrise() < 0) 
	return "���ڻ�û���㵱���ʱ���ء�";
	if (HELPER->is_sunrise() > 0) 
	    return "������î��ʱ���Ѿ����ˣ������������ɡ�";
	i = random(sizeof(inner_gate_name));
	player->set_temp("current_job", inner_gate_name[i]);
	return "���ȥ"+inner_gate_name[i]+"���� (guard) �ɡ�";
    case 3:	// fourth level
	if (HELPER->is_sunset() < 0) 
	    return "�컹�����أ��Ȼ���������Ϸ����";
	if (HELPER->is_sunset() > 0) 
	    return "�춼�����������������˵�ɡ�";
	i = random(sizeof(inner_gate_name));
	player->set_temp("current_job", inner_gate_name[i]);
	return "���ȥ"+inner_gate_name[i]+"���� (guard) �ɡ�";

    case 4:	// fourth level
    case 5:	// fifth level
    case 6:	// sixth level
	if ( player->query("biao/fail") )
	{
		player->delete("biao");
		penalty = ( 1 + player->query("biaoju/fail") * 10 / ( 1+ player->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		player->apply_condition( "biao", penalty );
		player->add("biaoju/fail",1);
		return "���ⲻ���õļһ���㻹������������Ҫ�����ڣ�\n";
	}
	if ( player->query_condition("biao") )
	{
		return "�����ﵹ�м�׮���£�������ʱ�Ų�����ȥ�ɣ�\n";
	}
	if ( (int)me->query_temp("biao") >= 1000 )
	{
		return "�������е��ڶ��������ˣ�������������ɡ�";
	}
	if ( player->query("biao") ) {
		command( "angry" );
		return "�㻹û���������ô�����ֶ�׮���£�\n";
	}
	command( "say �ðɣ�����������ʱ���������ȱ���á�");
	switch( random(7) )
	{
		case 0:
			player->set("biao/dest", "dao baifeng");
			player->set("biao/dest2", "/d/dali/yuxuguan");
			command("say �����ݶ����͵������������׷��Ƕ�������ڷ�ͬС�ɣ�һ��ҪС�ġ�");
			break;
		case 1:
			player->set("biao/dest", "hu laoye");
			player->set("biao/dest2", "/d/xingxiu/house");
			command("say ���Ǳ���С��������͵����ڣ���ö��С�ģ����˿��ⲻ��");
			break;
		case 2:
			player->set("biao/dest", "ye erniang");
			player->set("biao/dest2", "/d/xixia/dawu");
			command("say ����������͵�����Ҷ����ģ�������Խ�������");
			break;
		case 3:
			player->set("biao/dest", "wu tiande");
			player->set("biao/dest2", "/d/chengdu/tidufu");
			command("say ���з�Ҫ�͸��ɶ��ᶽ����µ��ڻ����������һ�˰ɡ�");
			break;
		case 4:
			player->set("biao/dest", "shi lang");
			player->set("biao/dest2", "/d/quanzhou/jiangfu1");
			command("say ����Ȫ�ݾ�������еĺ��ڣ���ͬС�ɡ���ǧ�򲻿ɴ��⣬��ؽ���������ʩ�����");
			break;
		case 5:
			player->set("biao/dest", "li kexiu");
			player->set("biao/dest2", "/d/city/ymzhengting");
			command("say �����͸�����ˮ½�ᶽ�������ڻ����������һ�˰ɡ�����ڻ���ͬС�ɣ���ǧ�򲻿ɴ��⡣");
			break;
		case 6:
			player->set("biao/dest", "liu haoyi");
			player->set("biao/dest2", "/d/chengdu/zijuefuhall");
			command("say �����͸��ɶ���Ϯ�Ӿ������ĵ��ڻ�����ȥ�������ֽ������Ӿ���");
			break;
	}
	message_vision( "$N�����е��������ţ�\n", me);
	player->apply_condition("biaoju",70);
	player->add("biao/times", 1);
	player->set_temp("apply/short", ({HIR"���־���ͷ  "NOR+player->name()+"("+player->query("id")+")"}));
	player->delete_temp("riding");
	player->remove_all_killer();
	biaoche = new(__DIR__"obj/gfbiaoche");
	biaoche->move("/d/beijing/jiaochang");
	biaoche->set_owner(player);
	me->add_temp("biao", 1);
	assign_biaotou(player,player);
	return "�ڳ���������������ǡ�����ҪС�����£���ν�������ڣ�����������������޶���ʱ�����������";
    default:
	return "����û���������";
    }
}

string ask_suicong()
{
    return "���ֻ��"+HELPER->rank_name(3)+"���ϵ��������С�\n"+
	"Ҫ����(ling)����أ�����������������ɵĶ��У����Լ����ɡ�\n";
}

int do_ling(string menpai)
{
    object player = this_player();
    object me = this_object(), suicong;
    int rank = SHIWEI_LEVEL(player);
    int suicong_num = player->query("suicong_num");
    string cmenpai;

    if (! IS_SHIWEI(player))
	return notify_fail("����ȥ����Ͷ���ɡ�\n");
    if (sync_mizheng(player)) 
	return notify_fail("�����µ��������Ƕ�ȥ�Ǽǰɡ�\n");
    if (HELPER->suicong_max(rank) == 0) 
	return notify_fail("��ļ��𲻹�����ӵġ�\n");
    if (suicong_num >= HELPER->suicong_max(rank)) 
	return notify_fail("���Ѿ���"+CHINESE_D->chinese_number(suicong_num)+
		"������ˡ�\n");

    if (! menpai || menpai == "")
	return notify_fail("��Ҫ��ʲô���ɵ���ӣ�\n");

    switch (menpai) {
        case "��ɽ��":
	case "��ɽ":
	    menpai = "huashan";
        case "huashan":
	    cmenpai =  "��ɽ��";
	    break;

        case "����":
	case "������":
	    menpai = "emei";
        case "emei":
	    cmenpai =  "������";
	    break;

 	case "�䵱":
	case "�䵱��":
	    menpai = "wudang";
        case "wudang":
	    cmenpai =  "�䵱��";
	    break;

	case "����":
	case "������":
	    menpai = "shaolin";
        case "shaolin":
	    cmenpai =  "������";
	    break;

	case "ؤ��":
	    menpai = "gaibang";
        case "gaibang":
	    cmenpai =  "ؤ��";
	    break;

	case "����":
	case "������":
	    menpai = "xingxiu";
        case "xingxiu":
	    cmenpai =  "����";
	    break;

	case "ѩɽ":
	case "ѩɽ��":
	case "Ѫ��":
	case "Ѫ����":
	    menpai = "xueshan";
        case "xueshan":
	    cmenpai =  "ѩɽ��";
	    break;

  	case "�һ�":
	case "�һ���":
	    menpai = "taohua";
        case "taohua":
	    cmenpai =  "�һ���";
	    break;

	case "����":
	case "����ɽׯ":
	    menpai = "baituo";
        case "baituo":
	    cmenpai =  "����ɽׯ";
	    break;

	case "��Ĺ":
	case "��Ĺ��":
	    menpai = "gumu";
        case "gumu":
	    cmenpai =  "��Ĺ��";
	    break;

	case "����":
	case "���չ�":
	    menpai = "lingjiu";
        case "lingjiu":
	    cmenpai =  "���չ�";
	    break;

        case "����":
	case "�������":
	case "dali":
	    return notify_fail("������ϵļҳ���ô�������ǵ�����أ�\n");

  	case "����":
	case "������":
	case "shenlong":
	    return notify_fail("�������ڹٸ����˾�׽�á���û���ɣ�\n");

        default:
                return notify_fail("��Ҫ��ʲô���ɵ����������\n");
                break;
        }
    suicong_num ++;
    player->set("suicong_num", suicong_num);
    suicong = new("/clone/npc/suicong.c");
    suicong->new_master(player, suicong_num, menpai);
    suicong->move(environment(player));
    suicong->set_leader(player);
    player->save();
    message_vision("$N��$n˵�����¹���Ҫһ��"+cmenpai+"����ӡ�\n",
		player, me);
    message_vision("$N������$n�ļ��Ц�����úã�û���⣬���˰���\n", 
		me, player);
    message_vision("$N�첽���˹�������$n���������ү�𰲡�\n",
		suicong, player);
    return 1;
}

private int is_suitable(object victim, object killer)
{
	string *no_kill_list = ({
	"mu ren",
	"huang zhen",
	"juexin dashi",
	"fighter dummy",
	"du e",
	"du nan",
	"du jie",
	"xie yanke",
	"ren woxing",
	"qu san",
	"yue buqun",
	"qiu chuji",
	"zhang sanfeng",
	"zuo lengchan",
	"ouyang zhan",
	"seng bing",
	"ma guangzuo",
	"black gargoyle",
	"white gargoyle",
	"tang nan",
	"zhu xi",
	"tangzi shou",
	"lao chaofeng",
	"hua tiegan",
	"yideng dashi",
	"lu tianshu",
	"liu chengfeng",
	"qu san",
	"zhao zhijing",
	"lu youjiao",
	"cheng buyou",
	"lin zhennan",
	"hong qigong",
	"master",
	"xun bu",
	"dongfang bubai",
	"du laoban",
	"ling tuisi",
	"zhao liangdong",
	"guai she",
	"duo long",
	"mi zheng",
	"liu haoyi",
	"rysj shizhe",
	"yang guo",
	});
	if(  !victim || !clonep(victim) || !living(victim) || userp(victim)
		|| victim->query("race") != "����"
		|| victim->query("shen") < 0
		|| victim->query("winner")
		|| strsrch(base_name(victim), "/kunfu/skill/") != -1
		|| strsrch(base_name(victim), "/clone/") != -1
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 1/4
		|| victim->query("combat_exp") > killer->query("combat_exp")*7/4
		|| victim->query("family/family_name") == "�һ���"
		|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
	{
		return 0;
	}
	return 1;
}

void do_leave(object ob)
{
	if( objectp(ob) )
	{
		if( ob->is_busy() || ob->is_fighting())
		{
			message_vision("$N���һ��������սȦ��\n",ob);
			message_vision("$N˵����������������һ�ȥ������Ԯ��\n���Ǽ��ؾ���ʤ����ǧ��Ҫ���˻��ϵ�Ӣ����\n",ob);
		}
		if(!living(ob))ob->revive(0);
		message_vision("$N����ææ�뿪�ˡ�\n",ob);
		destruct(ob);
	}
}

void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) ) return;
	if( obj->query("combat_exp") < me->query("combat_exp") )
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(50) )  );
	}
	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;
	if( obj->query("combat_exp") < 4000 )
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 30000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 60000)
	{
		level = level/2 + random(level/4);
	}
	else if( obj->query("combat_exp") < 300000)
	{
		level = level/2 + random(level/5);
	}
	else level = level/3 + random(level/6);
	skills = obj->query_skills();
	names = keys(skills);
	for (i=0; i<sizeof(names); i++)
	{
		obj->set_skill(names[i], level);
	}
	obj->set( "title", "���־�" );
	obj->delete( "nickname");
	obj->delete( "long");
	obj->delete( "family");
	obj->delete( "name" );
	obj->delete( "short" );
	if( obj->query("combat_exp") < 500000 ) obj->set_name("�ױ�", ({ "qin bing", "bing" }));
	else obj->set_name("��������", ({ "shi wei", "shi", "wei" }));
	call_out("do_leave",1000,obj);
}

void assign_biaotou(object me, object partner)
{
	object ob,here;
	object *target_list;
	int i;

	if( !userp(me) ) return;
	here = environment(me);
	if(!here) return;
	if( strsrch(base_name(here), "/d/") == -1 ) return;
	target_list = filter_array(livings(), "is_suitable", this_object(), me);
	if( sizeof(target_list) == 0 )
	{
		// try again in 5 secs.
		call_out("assign_biaotou", 5, me,partner);
		return;
	}
	do
	{
		i = random(sizeof(target_list));
		ob=new( base_name(target_list[i]) + ".c" );
	}
	while( !living(ob) );
	ob->move(here);
	setup_skill(me,ob);
	ob->set_temp("biao/owner",me->query("id") );
	if(partner)ob->set_temp("biao/owner2",partner->query("id") );
	ob->set_leader(me);
	message_vision("\n$N�첽���˹���!\n", ob);
	message_vision("\n$N��$n��ȭ������"+RANK_D->query_respect(me)+"�����ܹ���С�˸���һ��������ڡ�\n�������л������Ը���С�˾�����Ϊ����\n\n", ob,me);
}

string ask_abandon()
{
	object ob = this_player(), me = this_object();
	int penalty;

	if( !ob->query("biao") ) return "����û�����񣬷���ʲô��\n";
	command("angry");
	command("faint "+ob->query("id") );
	ob->delete("biao");
	if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
	penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) );
	ob->apply_condition( "biao", penalty );
	ob->add("biaoju/fail",1);
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	ob->delete_temp("apply/short");
	ob->delete_temp("apply/id");
	ob->remove_all_killer();
	return "���Ȼ�ѳ�͢�����ڶ��ˣ����ҹ�����\n";
}

private int is_suitable_rob(object victim, object killer)
{
	if(  !userp(victim)
		|| victim->query("race") != "����"
		|| victim->query("shen") > 0
		|| victim->query("xbiao/dest2") == 0
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 4/5
		|| victim->query("combat_exp") > killer->query("combat_exp") * 5/4
		|| victim->query_condition("biaoju") < 25)
	{
		return 0;
	}
	return 1;
}

string QueryDest(object obj)
{
	if ( obj->query("xbiao/dest") == "dao baifeng" ) return "�����������׷�";
	else if ( obj->query("xbiao/dest") == "hu laoye" ) return "����С�����";
	else if ( obj->query("xbiao/dest") == "ye erniang" ) return "����Ҷ����";
	else if ( obj->query("xbiao/dest") == "wu tiande" ) return "�ɶ��ᶽ�����";
	else if ( obj->query("xbiao/dest") == "shi lang" ) return "Ȫ�ݾ����";
	else if ( obj->query("xbiao/dest") == "le kexiu" ) return "����ˮ½�ᶽ�����";
	else if ( obj->query("xbiao/dest") == "liu haoyi" ) return "�ɶ��Ӿ�������";
	return "���صش�";
}
#include "/d/beijing/autok.h"
