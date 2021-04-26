// Code of ShenZhou
// Room: /d/xixia/ypshui.c

inherit ROOM;

void create()
{
	set("short", "Ӫ��ˮ");
	set("long", @LONG
�����ǵ��������޳���ʱפ���ĵط��������ξ��з�����������
�Դ�����פ�����˺ü�����ˮ����ʹʿ���ǲ��ú��ֿ���ɬ����ˮ��
�����˵صİ����ǽ�����ΪӪ��ˮ��������ľ�Ϊ�����񾮡���
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"oldwall",
  "southwest" : __DIR__"bcwan",
]));
       set("fjing", 1);
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
