// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "̫���Ͻ�");
	set("long", @LONG
    ̫�ͽ�������������ϱ��ţ���������ǳ�����Ҫ�ֵ�������������ڴ�
�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��ʳ��
���޲�������ԭ��
    ��������أ������Ǳ�Ӫ��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
