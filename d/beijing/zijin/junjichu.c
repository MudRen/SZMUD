//Cracked by Roath
// Room: /d/beijing/zijincheng/junjichu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��Ӻ������(1729)Ӻ��Ϊ��ǿ���뼯Ȩ,�ͼ�ʱ����ǲ��,���������.
Ǭ¡��λ��,��Ϊ����.��������������.
    �������������,�����¾��ȹ�ְ,�����ڴ�ֵ��,����ʵ��ټ�,��ͬ��
�̾���Ҫ��,Э���ʵ۴����������.
/*����һ��Сƽ��,������ӦΪ��ͷ������ֵ����,��ͷ������󳼰��´�,�м�
�Ǿ�����.���Ҳ�֪��������*/
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"xiaohuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
