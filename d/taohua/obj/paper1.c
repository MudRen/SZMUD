// Code of ShenZhou
// paper.c
inherit ITEM;

void create()
{
        set_name("�ż�", ({"letter paper", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"��ؤ�����ж��ޣ��ڼ��ɵ���༦����ʱ���������ӣ����·׷�˵κ�롣\n");
                set("material", "paper");
        }
}

