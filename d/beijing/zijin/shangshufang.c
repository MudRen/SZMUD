//Cracked by Roath
// Room: /d/beijing/zijincheng/shangshufang.c

inherit ROOM;

void create()
{
	set("short", "���鷿");
	set("long", @LONG
����һ���Ŷ�����ܣ������Ϸ������飬Ҳ��֪��ǧ���򱾡���
��һ�ż������̴ľ���������������Ƕ�������а����ӣ���������
���У�����һ��������ǽ�Ϲ��˲��������ֻ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qianqingmen",
  "east" : __DIR__"sikongchu",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
//����:����һ����̴ľ����������̯��һ���飬���ַ�����̨
//��Ͳ�����ַ���һֻ��¯��
//��¯:��¯�ʳ����ͣ�ͨ����������Ϊ�ף��κ������Ƕ��η�˿�����ƣ���
//�������η����ƣ�����˫��Ϸ��ͼ��

	setup();
	replace_program(ROOM);
}
