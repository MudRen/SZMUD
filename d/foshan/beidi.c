// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������������ϡ�Ժ����һ����ˮ��������ʯ��ʯ�ߣ���Ȼ�̾ᡣ
�������ʯ����Ѫ����Ȼ�������������ڴ�����С�
LONG
        );
        set("exits", ([
		"south" : __DIR__"street0",
	]));

/*	set("objects", ([
		__DIR__"npc/feng" : 1,
	]));
*/
	set("cost",1);
	setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_ketou","ketou");
	add_action("do_kaitang","kaitang");
}

int do_ketou(string arg)
{
	object me = this_player();
	if (!present("feng yiming",me) && !present("feng yiming",environment(me))) {
		message_vision("$N�ڱ���үү��ǰ���˼���ͷ��˵����������үү���������ɾ����书����\n",me);
		return 1;
	}

	message_vision("$N�ڱ���үү��ǰ���˼�����ͷ��˵����������үү��"+
		"�������Ժգ���"+ RANK_D->query_self(me)+ "\n��ԩ��ԩ���г𱨳�" +
		"������͵�����ҵķ���⣬�����˶�˵��û�ԣ���\n", me);
	me->set_temp("beidi-ketou",1);
	return 1;
}

int do_kaitang(string arg)
{
	object feng, feng_son;
        object me = this_player();
	object weapon;

	if (!arg)
		return notify_fail("Ҫ��ɱ��\n");
	if( arg !="feng" && arg !="feng yiming" && arg !="yiming"
		|| !me->query_temp("beidi-ketou")) 
		return notify_fail("������ǰ��������Σ�\n");
	if ( !feng_son = present("feng yiming",environment(me)))
		return notify_fail("�����������\n");
	
        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword"
        && (string)weapon->query("skill_type") != "blade" )
        	return notify_fail("���ſ���Ҫ�ù��ߵġ�\n"); 

	if(present("feng tiannan",environment(me))) {
		message_vision("�����϶�$N�������������Ҷ�����\n", me);
		return 1;
	}

	message_vision("$N��ס��һ�����½�����һ����¶���Ǹ����������" + weapon->query("name") +
		"���е��������Ƿ���˷���⣬��������۾��Ƹ����ף���˵��ԩ�����ˣ���\n", me);
	message_vision("��Ȼ�䣬��������һ�ˣ���$N�ȵ����������Ҷ���������һ���˻������ˡ�\n", me);
	feng = new(__DIR__"npc/feng");
	feng->move(environment(me));
	feng->kill_ob(me);
	destruct(feng_son);
	me->delete_temp("beidi-ketou");
	return 1;	
}	
