// /d/jueqing/shi2.c  ����
// By jiuer

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG 
���Ǽ�ϴ�ķ��䡣���д�����Σ�ȫ���Ĺ�е�������ͬ������
������齣������������һ����������ǰССһ������������һ���ֲ�
ľ����ֻ�ǹ�Ĺ���þߴ�ʯ�ƣ��˴���ȴ�ɴ�ľ��ɡ�
LONG);
	
	set("exits",([ 
		"west" : __DIR__"shi1",
		]));
	
	set("sleep_room", 1);
	set("cost",1);
	setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);

        if ( dir == "west" ) {
			for (i=0; i<sizeof(inv); i++) {
				if (inv[i]->is_character())
					return notify_fail("�㲻�ܴ�����������뿪��\n");
			}
		}
		return ::valid_leave(me, dir);
}