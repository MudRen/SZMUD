// Code of ShenZhou
//kane

inherit ROOM;

int do_tanzhi();
void create()
{
	set("short", "��ָ��");
	set("long", @LONG
�����������һ�������ߵ㣬�Ӹ����£�ȫ�����۾����۵ס��ϱ��Ǻ�������
��һЩ��ͺͺ����ʯ�����汱�涼�ǻ�������ɫ�ͷף�������ͷ��ֻ������ͷ����
�����嶥��һ��ʯ���������������֡���ָ�塱��������һ��ʯ��������֮������
��׭����Ȼ��ĥ���٣�������ϡ�ɱ档ϸ��֮��ԭ���ǡ������������֡�
LONG
	);
	 set("exits", ([
                "enter" : __DIR__"qingyin",
                "southdown" : __DIR__"shanlu2",
        ]));
        
	set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));

	set("cost", 5);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

