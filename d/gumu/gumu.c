// July 31,2000
// Code by April
// /gumu/gumu.c

inherit ROOM;

void create()
{
	set("short","��Ĺ");

	set("long",@LONG						
������ǰ������һ����Ĺ��Ĺ���Ϸ��м���ʯ�̴��֣�zi������˵��
�ǵ���һλ��������Ϊ�ֿ������������ǧ��������ʱ���귽ʼ���ɡ�Ĺ
������������ʯ�����������С��Ů���������£������ּ�������֮��
�����򿪡���������ҡҡ��׹������ʮ��Σ�ա�
LONG);

	set("item_desc",(["zi" : "
                       �ԡԡԡԡԡ�
                       �ջ�����Ĺ��
                       �ԡԡԡԡԡ�
\n",]));

	set("exits",([
		"enter" : __DIR__"mudao1",
		"south" : __DIR__"milin3",
	]));

	set("objects", ([
//		"/kungfu/class/gumu/npc/huangyi_gate" : 1,
	]));    

	set("cost",1);

	set("outdoors", "gumu");
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;

	fam = (mapping)me->query("family");

	if(( fam && fam["family_name"] != "��Ĺ��" 
		&& me->query("combat_exp") > 10000 ) 
                && dir == "enter"
		&& objectp(present("huangyi girl", environment(me))) ) 
	{
		return notify_fail("������Ů������Ĺ���أ�����ֹ����\n");
	}
	return ::valid_leave(me, dir);
}

