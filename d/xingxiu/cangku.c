// Code of ShenZhou
// Room: /d/xingxiu/xxroad5.c

inherit ROOM;

void create()
{
        set("short", "�����ɴ�����");
        set("long", @LONG
����ԭ����һ������ɽ���ϵ���Ȼ�ܶ�����Ϊ�ص����ܶ��Ҷ��п���ʮ��
��������ɰ�����������һ���ֿ⡣
LONG
        );
        set("exits", ([
  "out" : __DIR__"xxroad5",
]));
        set("objects", ([
                __DIR__"obj/hulu"  : 2,
                DRUG_D("menghan_yao")  : 1,
                __DIR__"obj/dujing_1"  : 1,
		__DIR__"obj/lianxin" : 1,
                DRUG_D("xxqingxin-san") : 1]));

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
        replace_program(ROOM);
}
