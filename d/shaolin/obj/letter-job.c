// Code of ShenZhou
// letter-job.c �Ƽ��� 

inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({"tuijian xin", "xin", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ȷ���д�������ھֶ�����ͷ���Ƽ��š�\n");
                set("no_drop", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}

