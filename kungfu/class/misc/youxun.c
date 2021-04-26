// Code of ShenZhou
// ���������֡���Ѹ���ұ�����npc
// by maco 

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
#include "/d/REGIONS.h";

string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
        "/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/taishan/huima",
        "/d/village/square",
        "/d/xingxiu/tianroad3",
        "/d/emei/baoguomen",
        "/d/emei/xixiang",
        "/d/qilian/qilian",
        "/d/dali/taihejie2",
        "/d/xixia/square",
});


void create()
{
        set_name("��Ѹ", ({ "you xun", "you","xun" }) );
        set("long", "����������ۣ�ͷ����ͺ��һ�����룬�ʷ����֣�������⣬\n����ʮ�ֺͰ����ף����λ����Ǹ�����ģ����\n");
	set("nickname", "��������");
        set("gender", "����");
        set("age", 48);
        set("attitude", "friendly");
        set("str", 16);
        set("int", 26);
        set("con", 18);
        set("dex", 30);
        set("max_qi", 500);
        set("max_jing", 300);
	set("max_jingli", 600);
	set("jingli", 600);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 100000);
	set("no_get","������ųƻ������֣�������ץ����ס��");
	set("special_npc",1);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set_skill("dodge", 100); 
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 100);

        set("inquiry", ([
                "�ͽ�����" : "���ǽ���������̧���������ֵܵ��Ṧ���費���������һ�����ݣ���ʵ�����ý�����һ��΢ĩ����ʵ�ڲ���ҳݡ�",
		"��������" : "�ֵ��и���������ţ��������������֡������˵�ֵܰ��ύ���ѣ�Ϊ�����ѣ��ֵ���ǧ��������������ϧ����Ȼ׬��Ǯ�࣬����ȴ������������ס�ġ�" ,
		"rumors" : "���Ե��úã���������ʿ����������ˣ�����Ϣ��Ե������������ֵ������Ĳ��ǹ��ӣ�������Ϣ����һ�������ӣ��ұ�˵��������" ,
		"��Ϣ" : "�ֵ��书ƽƽ����Ϣȴʮ����ͨ������������ô����ѶϢ��Ҫ�����ֵܵ�ǧ���ۡ�˳������ɲ������ס�" ,
		"ѶϢ" : "�ֵ��书ƽƽ����Ϣȴʮ����ͨ������������ô����ѶϢ��Ҫ�����ֵܵ�ǧ���ۡ�˳������ɲ������ס�" ,
		"��а����" : "��Ӵ����Ҳ��������а���ס���������֪���⽣�׿ɲ�����������а���",
		"gold" : "��λ֪���ֵܵ���Ž������������֡���Ǯ��������������ȥ���⼸��ʵ�����Ҫ������λ���Ǵ��������һ����ë��Ҳ���ֵܵ����Ӵ֡�",
		"����Ⱥ" : "���������һ����Ϲһʮ����ǿ�У��������𽭺���С�����������Ͷ�ء��ý������ý�����",
		"�����" : "�ֵܴӶ����������ò��ٽ��������ᵽ������ӵĴ��������º�����Ľ��" ,
		"�����" : "�ֵܴӶ����������ò��ٽ��������ᵽ������ӵĴ��������º�����Ľ��" ,
        ]) );

        setup();
        carry_object("/d/xiakedao/npc/obj/bluerobe")->wear();
}

void init()
{
        object ob;
        ::init();
	add_action("do_find","find");
}


int do_find(string arg)
{
        object *obs, *ppl, ob, where, fake, me = this_player();
        string region, baowu, env, putin;
	int i,k=0,exp = 0,kar;

        if( !living(this_object()) )
                return notify_fail("��....����Ȱ���ѸŪ����˵��\n");

	if (!arg) return notify_fail("������ʲ�ᱦ�\n");
	
	if (me->query_temp("asked_youxun") && me->query_temp("find_gold")) 
		message_vision(CYN"$N���ͷ��س���Ѹ���ʣ���˵��"+arg+"��������˭�����\n\n"NOR, me);
	else message_vision(CYN"$N����Ѹ�ʵ������ڽ����ϣ���˭����"+arg+"��\n\n"NOR, me);
 
	switch(arg) {
		case "��ħ��": baowu = "/clone/weapon/xiangmo-chu.c"; break;
		case "���콣": baowu = "/clone/weapon/yitian-jian.c"; break;
		case "������": baowu = "/clone/unique/tulong-dao.c"; break;
		case "����": baowu = "/clone/unique/yuxiao.c"; break;
		case "�򹷰�": baowu = "/clone/unique/yuzhu-zhang.c"; break;
		case "��ħ��": baowu = "/clone/unique/fumo-dao.c"; break;
		case "���߽�": baowu = "/clone/unique/jinshe-jian.c"; break;
		case "�����": baowu = "/clone/unique/eyujian.c"; break;
		case "��β��": baowu = "/clone/unique/eweibian.c"; break;
		case "������":
		case "�����ؽ�": baowu = "/clone/unique/xuantie-jian.c"; break;
		case "�߾���": baowu = "/clone/weapon/qijue.c"; break;
		case "�㳦��": baowu = "/clone/unique/yuchang-jian.c"; break;
		case "���佣": baowu = "/clone/unique/zhenwu.c"; break;
		case "������": baowu = "/clone/unique/cy-jian.c"; break;
		case "�����": baowu = "/d/shaolin/obj/jingang-zhao.c"; break;
		case "�ڲ���": baowu = "/d/xueshan/obj/wucan-yi.c"; break;
		case "��⬼�": baowu = "/d/taohua/obj/ruanwei-jia.c"; break;
		case "Ѫ��": baowu = "/clone/unique/xuedao.c"; break;
		case "ԧ��": baowu = "/clone/unique/yuandao.c"; break;
		case "�쵶": baowu = "/clone/unique/yangdao.c"; break;
		case "������": baowu = "/clone/unique/dulong-bian.c"; break;
		case "��ɥ��": baowu = "/clone/unique/kusang-bang.c"; break;
		case "����ȭ��": baowu = "/clone/unique/qs-jing.c"; break;
		case "��ľ����": baowu = "/d/xingxiu/obj/muding.c"; break;
		case "���վ�": baowu = "/d/city/npc/obj/shenzhao.c"; break;
		case "����": baowu = "/d/taohua/obj/luoshu"; break;
		case "��ͼ": baowu = "/d/taohua/obj/hetu"; break;
		case "�����񹦲�ƪ": baowu = "/kungfu/class/wudang/obj/canpian.c"; break;
		case "�����澭": baowu = "/clone/unique/jiuyin_force_book.c"; break;
		case "��������": 
		case "�����ܼ�": 
		case "�����ؼ�": 
		case "��������": baowu = "/d/huashan/obj/jinshe_book2.c"; break;
		case "���������": baowu = "/d/xueshan/obj/lx-jing.c"; break;
		case "����": baowu = "/d/xingxiu/obj/yaobo.c"; break;
		case "������": baowu = "/clone/weapon/bailong-jian"; break;
		default: baowu = "none";	break;
		}


	if(baowu == "none" && !is_chinese(arg)){
	command("say �ף�������������᣿�ֵܿɲ�֪���ˡ�");
	return 1;
	}
	
	if(baowu == "none"){
	command("say Ŷ������ʲ�ᱦ�����ֵܻ���û��˵����");
	return 1;
	}

	ob = 0;
        obs = filter_array(children(baowu), (: clonep :));

        if (sizeof(obs) == 0){
	command("say ���"+arg+"�����������ƺ�û�˼�������");
	me->delete_temp("asked_youxun");
	return 1;
	}

        if (sizeof(obs) > 1 && wizardp(me)) 
        write("һ����"+chinese_number(sizeof(obs))+"����\n");

        ob = obs[0];
	where = environment(ob);

	//if target put baowu in yaodai or budai, You Xun will know it
	if (!living(where) && living(environment(where))) {
	putin = where->name();
	where = environment(where);
	env = where->query("short");
	}
	else if (!living(where) ) {
	env = where->query("short");
	command("say ���"+arg+"�����������ƺ�û�˼�������");
		if (wizardp(me))
		write("��Ѹ����Ķ�������˵������ʵ"+ob->name()+"����"+env+"("+base_name(where)+")��\n");
	me->delete_temp("asked_youxun");
	return 1;
	}

	if (!me->query_temp("find_gold")) {
	command("walkby");
	message_vision(CYN"��ѸЦ���������������˵������һ�������ӣ��ұ�˵��������\n"NOR, me);
	me->set_temp("asked_youxun",1);
	return 1;
	} 

	ppl = all_inventory(environment(me));
	for(i=0; i<sizeof(ppl); i++) {
		if( !living(ppl[i]) ) continue;
		k++;	}

	if( k > 2 ) {
	command("say �������ڣ���ɲ���˵�ˡ���Ҫһ�������ӣ���ÿ��һ�������ɲ��ǽ��������Ϣֻ��һ�������ӡ���˴�������������д���");
	command("hehe you xun");
		return 1;
	}

	
	if (where->query("combat_exp") > 1000000 && 
	where->query("combat_exp") > me->query("combat_exp")*3/2 ) {
	command("say �ã��ұ�˵�ˣ�ֻ����"+RANK_D->query_respect(me)+"���ڶ��ȴ������������Ҳ�޿��κΡ���"+arg+"����Ϊ�������ã�Ҳ���м���ָ��������ƫƫ������һλ�������У��Ǿ͡����Ǿ͡����ȿȣ��������");
	}
	ppl = users();
	for( i = 0; i < random(sizeof(ppl)+1); i++) {
		if( ppl[i]->query("combat_exp") > random(exp) 
		&& !wizardp(ppl[i])
		&& environment(ppl[i])
		&& strsrch(file_name(environment(ppl[i])), "/d/") >= 0) {
			fake = ppl[i];
			exp = fake->query("combat_exp");
		}
	}

		if(where == me) {
		command("say "+RANK_D->query_respect(me)+"�Լ���֪�������ѵ���Ҫ�ֵܶ������᣿");
		command("hehe");
		command("escape");
		me->delete_temp("asked_youxun");
		me->delete_temp("find_gold");
		message_vision("��Ѹ����ææ���뿪�ˡ�\n", me);
		return move(load_object(homes[random(sizeof(homes))]));
//		destruct(this_object());
		}
		kar = me->query_kar()/3;
		if( kar > 10) kar = 10;
		if( kar < 2) kar = 2;
		
		if (random(kar) == 1) {
	//	env = fake->name()+"("+fake->query("id")+")"; //��ѶϢ
		where = fake;
		}

		env = where->name(); 

	command("hehe");
	command("say �͸�����ɣ���"+arg+"�أ���������"+env+"("+where->query("id")+")"+"���ϡ�");
	if(putin) command("say ��˵"+gender_pronoun(where->query("gender"))+"�ǰ�"+arg+"���ڸ�"+putin+"���档");
	command("say �Ų������㣬�ֵܿ�Ҫ�����ˡ��⻰Ҫ�Ǵ���"+env+"�����Ҫ����ĳ���鷳��");
	message_vision("��Ѹ����ææ���뿪�ˡ�\n", me);
	me->delete_temp("asked_youxun");
	me->delete_temp("find_gold");
//	destruct(this_object());
	move(load_object(homes[random(sizeof(homes))]));

	me->start_busy(1);

	me->delete_temp("asked_youxun");
	me->delete_temp("find_gold");
	return 1;
}


int accept_object(object who, object ob)
{
        object me = this_player();
	if(me->query("combat_exp") < 10000)
		return notify_fail("�����߽����ľ���̫�٣�ʮ֮�˾Ż����Ѹƭ�ţ��������ˡ�\n");

        if (ob->query("money_id") && ob->value() >= 1000000 ) 
        {
                who->set_temp("find_gold",1);
		message_vision(CYN"\n��Ѹ�ӹ����ӣ������е��˵࣬˵������Ͷ�л�ˡ�\n"NOR, me);
		command("rich you xun");
		write(YEL" (ָ�find <������������> )\n"NOR);
		return 1;
        }
        else if (ob->query("money_id") && ob->value() < 1000000) 
        {
		command("rich you xun");
		command("say ��Դ���������ƣ����߲��ܣ�");
                return 1;
        }

        return 0;
}

