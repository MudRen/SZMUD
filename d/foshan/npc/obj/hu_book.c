
// Code of ShenZhou
// sword_book.c

inherit ITEM;
void create()
{
        set_name("���ҵ�����ƪ", ({ "hujia daofa", "book", "daofa" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                "���Ǻ�һ��������ĩ��������������������Ľ��ġ����ҵ�������ǰ��ҳ�����潲��Щ����������֪ʶ�����⻹�ᵽ����ķ�����������ù���һ�ѱ�����\n");
                set("value", 100);
                set("material", "paper");
                set("skill", ([
                        "name":                 "blade",                // name of the skill
                        "exp_required": 1000,                   // minimum combat experience required
                                                                                        // to learn this skill.
                        "jing_cost":            30,                             // jing cost every time study this
                        "difficulty":   20,                             // the base int to learn this skill
                                                                                        // modify is jing_cost's (difficulty - int)*5%
                        "max_skill":    40                              // the maximum level you can learn
                                                                                        // from this object.
                ]) );
        }
}
