// Code of ShenZhou
// Room: mantx.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ������ƽԭ����������û���κ�Сɽ���꣬����һ����Ҳ��
������̧����ȥ����ƽ�߱�ֱ�Ľ�������ѩԭ�ָ������ߡ�ҹ��������
�����ڵ����ɱ�������Ƕ�����ɽ�����Ƕ��ڴ������ϲԵı��ӡ�
LONG	);
	set("exits", ([ 
              "west" : __DIR__"ermk",
              "southeast" : __DIR__"gucd",
        ]));
	
        set("objects",([
        //      "kungfu/class/shenlong/lu" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}
