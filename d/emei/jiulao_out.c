// Code of ShenZhou
// d/emei/jiulao_out.c ���϶���
// xbc: 96/02/02
// 18th-Aug-2000: modified by yasuko
inherit ROOM;

void create()
{
        set("short", "Сɽ��");
	set("long", @LONG
��ǰ��Ȼһ����ԭ���Ǿ��϶����һ��Сɽ�¡�ɽ���������˻��ݣ���Զ
����һ��ܼ�ª��С���ӡ�С�����пò���Ĵ��������������Χ���������
�����ż���С�ضѣ���ǰ�����������겻�ϡ�
LONG);
        set("exits", ([
                "north" : __DIR__"jiulao1",
        ]));
        set("objects",([
		"/kungfu/class/emei/zhou.c" :1,
        ]));
	set("invalid_startroom", 1);
	set("outdoors", "emei" );
	set("cost", 1);
	setup();
}
