// Code of ShenZhou
inherit ITEM;

void create()
{
        set_name("����ɨҶ���ķ�", ({"xin fa", "book", "fa"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"һ�ű�ֽ��������������д����ӬͷС����\n");
                set("material", "paper");
                set("skill", ([
                        "name": "kick", // name of the skill
                        "exp_required": 0,      // minimum combat
                        "jing_cost": 10,        // jing cost every time
                        "difficulty":   20,     // the base int to learn
                        "max_skill":    30,    // the maximum level you
                ]) );
        }
}

