// Code of ShenZhou
// Room: /d/village/bighouse2.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�����ң������м���һ�Ŵ󴲣����ϵı����Ȼ�ǳ�еģ�������һ
��С��ׯ��������˵��ֹ���ȷ�����˳Ծ�������������������Լ�������ʮ�ֿ�
����������ż�ֻľ���ӣ�ǽ������һֻ�����(cabinet)����ɫ�������ζ����
����ǰȥ������ϸ��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" :"/d/village/bighouse1",
        ]));
	set("item_desc", ([
	"cabinet" : "����һ�����µ�С���ӣ��οյĻ�����û��һ˿�ҳ����������˾�����ɨ�����ӡ�\n",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
