// Code of ShenZhou
inherit ITEM;

void create()
{
        set_name("��", ({"xin", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                
set("long","����һ�������д����ü��ʦ���š�\n");
                set("no_get", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}













