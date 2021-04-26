// Code of ShenZhou
// hsstreet2
// qfy Oct 15, 97

inherit ROOM;

void create()
{
	set("short", "������·");
	set("long", @LONG
�������ׯ��Զ�����ҵ��Զ������֣��ڵ�·��Ͷ�´�Ƭ��Ӱ���о�
������ˬ��һ���������м�Ƭ��Ҷ���衣·����ϡ�м���С��ͨ�����С�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	"southeast" : __DIR__"hsforest7",
	"northeast" : __DIR__"hsforest1",
	"west" : __DIR__"hsstreet1",
	"east" : __DIR__"hsstreet3",
]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 2);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object ob, *inv, master;
	int i;

	if ( dir == "northeast" || dir == "southeast" )  {
		if ( objectp(ob=me->query("rided")) )
			return notify_fail(ob->name()+"����̫���ˣ����������֣�\n");
		else {
			inv = all_inventory(me);
			for (i=0; i<sizeof(inv); i++) {
                		if ( (string)inv[i]->query("ridable") )
					return notify_fail(inv[i]->name()+"����̫���ˣ��㱳�������֣�\n");
			}
        	}

		if ( me->query("ridable") ) {
			if ( objectp(master=me->query_lord()) ) {
				tell_object(master, me->name()+"����̫���ˣ����������֣�\n");
			}

			return notify_fail(me->name()+"����̫���ˣ����������֣�\n");
		}
        }

        return ::valid_leave(me, dir);
}