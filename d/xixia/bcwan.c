// Code of ShenZhou
// Room: /d/xixia/bcwan.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������Ӫ��ˮ�����ϣ�ƽʱ�˼���������Ϊ����ɳĮ�ﳤ��һ�������ҩ
�ݡ��������ݡ�����������˵����ҩ���ܽ�ٶ�������ż�����������ֲݣ�����
ɳĮ�ﳣ�ж����û����ΪΣ�ա�
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("bing_can", 2);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ypshui",
  "southwest" : __DIR__"shixiazi",
]));
	switch(random(3)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/snake" : 1,
				  "/d/xingxiu/npc/spider" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        }
	setup();
	replace_program(ROOM);
}
