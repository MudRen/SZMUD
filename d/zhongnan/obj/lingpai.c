// Code of ShenZhou
// /d/zhongnan/obj/lingpai.c
// lingpai.c ȫ�������
// sdong 06/01/99

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
		  set_name("ȫ�������", ({"ling pai", "pai"}));
		  set("long",
					 "����һ��ͭ�Ƶģ�����ķǳ����¡�\n");
		  set("unit", "��");
		  set("weight", 10);

		  set("no_get",   "ƥ������������㻹�����˰ɡ�\n");
		  set("no_steal", "���������͵������\n");

}
