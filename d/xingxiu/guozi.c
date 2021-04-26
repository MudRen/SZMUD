// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;
string look_bei();
void create()
{
	set("short", "���ӹ�");
	set("long", @LONG
���ӹ���Ұ��������Ҫ�ֲ���ͷ̨�����ļ�ʮ��ɽ���ϣ�����ͷ̨
�Ļ�������ޡ�����ɫ��Ұ������˳��ɽ��һ������Ͽ���һ������һ
�شأ������ޣ���������ֱ��ɽ���������ϵĲ������ӣ�ǧ�˰�̬����
���У��Ƴ�ϼ���������Ҳ���ŵ�����Ļ��㡣�����п�ССʯ��(bei)��
LONG
	);
	set("exits", ([
                "east" : __DIR__"ertai",
                "northup" : __DIR__"tianchi",
        ]));
	set("objects", ([
		"/d/city/npc/obj/apple" : 1,
		"/d/wudang/obj/mitao" : 1,
		"/d/city/npc/obj/pear" : 1,
		"/d/xingxiu/obj/hamigua" : 1,
	]));
	set("item_desc",([
                "bei"         :       (: look_bei :),
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
}
string look_bei()
{
        return
        "\n"
        "                   ��    ��    ��\n\n"
	"                   ¶    ��    ��\n\n"
	"             Ү    ��    ��    ��\n"
	"             ��		  \n"
	"             ��    ɫ    ��    ��\n"
	"             ��                  \n";
}
