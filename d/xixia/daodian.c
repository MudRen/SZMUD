// Code of ShenZhou
// Room: /d/xixia/daodian.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����������ز���Ӣ������С�������ı����̣��ϰٰѸ�ʽ
�����ġ�Ӣ������С����������İڷ��ڹ�̨�ϣ�˵��С��ȴ�ߴ�����
����ͬ�����г���һ�����Ҷ�ɵ���Ҳ�г������ߵİ������䵶����
��Ļ��ǳ����磬�����֣�����һ���б���ֽ��ذ�׹�̨�����ǽ��
Ҳ����Щ�������ֵ������ȵ���ԭ������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xidajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
