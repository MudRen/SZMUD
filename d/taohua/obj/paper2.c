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
"�쳤�ؾã�������ʱ���Ⱥ��޾����Ӷ����ڡ�\n");
                set("material", "paper");
        }
}

