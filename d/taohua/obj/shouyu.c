// Code of ShenZhou
// 
inherit ITEM;

void create()
{
        set_name("��ҩʦ����", ({"shou yu", "yu", "letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","\n
=================================
|				|
|		��		|
|		��		|
|		��		|
|		��		|
|		��		|
|		ͽ		|
|				|
|			��	|
|			��	|
|			��	|
|				|
|			��	|
|				|
=================================\n");
                set("material", "paper");
        }
}
