// Code of ShenZhou
// Room: gbdixiaoshi.c
// by aji

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
���߽���һ��С�ݡ�����ǽ�ڶ�����������ɣ�������һ���޼ʵ����֡���
������Ρ����̾�Ϊ���ơ���һ���˱Ƕ����Ĺ�����ζ��ȴ�Ե��������ŵ�����
����롣
LONG );

	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"zhulin2",
		"northwest" : __DIR__"zhulin3" ]));

	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
	]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
	set("cost", 0);
        setup();

//	"/clone/board/gaibang_r"->foo();
}
/*
void init()
{
	mapping fam;
	object me = this_player();

	if( !mapp(fam = me->query("family")) ) return;

	if( fam["family_name"] == "ؤ��" && me->query_skill("staff", 1) > 5 && me->query_skill("stick", 1) < 5 ) {
		tell_object(me, HIY "\n\n" +
				"���Ǹ�ؤ����ӣ���ѧ�˻����ȷ������ǽ���ؤ�ｫʹ�û���������stick��\n" +
				"ȡ�������ȷ���staff���������Ը��Ļ���ϵͳ���Զ�������ȷ���Ϊ������\n" + 
				"����롰yes�����иı䡣\n\n" NOR);
	
		add_action("do_yes", "yes");
	}

	if( fam["family_name"] == "ؤ��" && me->query_skill("unarmed", 1) > 0 && me->query_skill("strike", 1) <= 0 ) {
		tell_object(me, HIY "\n\n" +
				"���Ǹ�ؤ����ӣ���ѧ�˻���ȭ�ţ����ǽ���ؤ�ｫʹ�û����Ʒ���strike��ȡ������ȭ��\n" + 
				"��unarmed�����Է��Ͻ���ʮ���Ƶ����ơ� �����Ը�⣬ϵͳ���Զ�����Ļ���ȭ�Ÿ�Ϊ�Ʒ���\n" + 
				"����롰ok�����иı䡣\n\n" NOR);
	
		add_action("do_ok", "ok");
	}

        add_action("do_kill","kill");

}

int do_yes()
{
	mapping learned; 

	object me = this_player();
	learned = me->query_learned();

	me->set_skill("stick", me->query_skill("staff", 1));
	me->improve_skill("stick", learned["staff"]);
	if( me->query_skill("dagou-bang", 1) > 1)  me->map_skill("stick", "dagou-bang");
	me->map_skill("staff");
	me->delete_skill("staff");

	tell_object(me, HIY "\n���ܸ�����ϣ� �к����⣬������ʦ���档\n\n" NOR);	

	return 1;
}

int do_ok()
{
	mapping learned; 

	object me = this_player();
	learned = me->query_learned();

	me->set_skill("strike", me->query_skill("unarmed", 1));
	me->improve_skill("strike", learned["unarmed"]);
	if( me->query_skill("xianglong-zhang", 1) > 1)  { 
		me->map_skill("strike", "xianglong-zhang");
		me->prepare_skill("strike", "xianglong-zhang");
	}
	me->map_skill("unarmed");
	me->delete_skill("unarmed");

	tell_object(me, HIY "\n���ܸ�����ϣ� ��������ʹ�ý���ʮ���ƣ����� enable strike xianglong-zhang ��\n" + 
			"�ټ��� prepare xianglong-zhang ��ɼ���׼���� ����ɼ��� prepare none ȡ������׼����\n" + 
			"����ϵͳ���Զ���������������񣬽����к����⣬������ʦ���档\n\n" NOR);	

	return 1;
}
*/
int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

//     	message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ:)��\n", ob, me);

        if ( ob->query("family/family_name") == "ؤ��" 
	&& me->query("family/family_name") != "ؤ��"
        && ob1=present("hong qigong", environment(me)) ) {
                	message_vision("$Nһ����Ц���󵨿�ͽ����Ҳ̫С�����Ͻл��˰ɣ�\n", ob1);
                	ob1->kill_ob(me);
	}

       	return 0;
}
