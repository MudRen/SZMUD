// random_name.c ��������⡣
//��ȨΪ�����ݡ���ʦ����߼���ʦ���С�

static mixed xing = ({
({"��","zhao"}),({"Ǯ","qian"}),({"��","sun"}),({"��","li"}),({"��","zhou"}),({"��","wu"}),({"֣","zhen"}),({"��","wang"}),
({"��","feng"}),({"��","chen"}),({"��","zhu"}),({"��","wei"}),({"��","jiang"}),({"��","shen"}),({"��","han"}),({"��","yang"}),
({"��","zhu"}),({"��","qing"}),({"��","you"}),({"��","xu"}),({"��","he"}),({"��","lv"}),({"ʩ","shi"}),({"��","zhang"}),
({"��","kong"}),({"��","cao"}),({"��","yan"}),({"��","hua"}),({"��","jin"}),({"κ","wei"}),({"��","tao"}),({"��","jiang"}),
({"��","qie"}),({"л","xie"}),({"��","zou"}),({"��","yu"}),({"��","bo"}),({"ˮ","shui"}),({"�","dou"}),({"��","zhang"}),
({"��","yun"}),({"��","su"}),({"��","pan"}),({"��","ge"}),({"��","duan"}),({"��","fan"}),({"��","peng"}),({"³","lu"}),
({"Τ","wei"}),({"��","chang"}),({"��","ma"}),({"��","miao"}),({"��","feng"}),({"��","hua"}),({"��","fang"}),({"��","ren"}),
({"Ԭ","yuan"}),({"��","liu"}),({"��","deng"}),({"��","bao"}),({"ʷ","shi"}),({"��","tang"}),({"��","fei"}),({"��","lian"}),
({"�","chen"}),({"Ѧ","xue"}),({"��","lei"}),({"��","he"}),({"��","ni"}),({"��","tang"}),({"��","teng"}),({"��","yin"}),
({"��","luo"}),({"��","hua"}),({"��","hao"}),({"��","tian"}),({"��","an"}),({"��","chang"}),({"��","jin"}),({"ʱ","shi"}),
({"��","fu"}),({"Ƥ","pi"}),({"��","bian"}),({"��","qi"}),({"��","kang"}),({"��","wu"}),({"��","yu"}),({"Ԫ","yuan"}),
({"��","gu"}),({"ƽ","ping"}),({"��","huang"}),({"��","he"}),({"��","mu"}),({"Ф","xiao"}),({"��","yin"}),({"Ҧ","yao"}),
({"��","shao"}),({"տ","zhan"}),({"��","wang"}),({"��","qi"}),({"ë","mao"}),({"��","yu"}),({"��","di"}),({"��","mi"}),
({"��","bei"}),({"��","ming"}),({"��","zang"}),({"��","ji"}),({"��","ji"}),({"��","cheng"}),({"��","dai"}),({"̷","tan"}),
({"��","song"}),({"é","mao"}),({"��","pang"}),({"��","xiong"}),({"��","ji"}),({"��","su"}),({"��","qu"}),({"��","xiang"}),
({"ף","zhu"}),({"��","dong"}),({"��","liang"}),({"��","fan"}),({"��","hu"}),({"��","ling"}),({"��","ho"}),({"��","yu"}),
({"��","wan"}),({"��","ke"}),({"��","guan"}),({"¬","lu"}),({"Ӣ","ying"}),({"��","qiu"}),({"��","hou"}),({"��","yue"}),
({"˧","shuai"}),({"��","nian"}),({"١","dong"}),({"��","kuai"}),({"��","zhong"}),({"��","zong"}),({"��","lin"}),({"ʯ","shi"}),
({"˾��","sima"}),({"�Ϲ�","shangguan"}),({"ŷ��","ouyang"}),({"�ĺ�","xiahou"}),({"���","zhuge"}),({"����","dongfang"}),
({"�Ϲ�","nangong"}),({"����","huyan"}),({"�ʸ�","huangpu"}),({"����","gongsun"}),({"���","linghu"}),({"����","yuwen"}),
({"����","zhangsun"}),({"Ļ��","murong"}),({"˾ͽ","situ"}),({"����","ximen"}),({"��","yu"}),({"Ī","mo"}),
});

static mixed name = ({
({"��","zhong"}),({"Т","xiao"}),({"��","li"}),({"��","yi"}),({"��","zhi"}),({"��","yong"}),({"��","ren"}),({"��","kuang"}),
({"��","xian"}),({"��","ling"}),({"��","fu"}),({"»","lu"}),({"��","da"}),({"С","xiao"}),({"��","xiao"}),({"��","gao"}),
({"��","ke"}),({"��","a"}),({"��","jin"}),({"��","shi"}),({"��","ke"}),({"��","shu"}),({"֮","zhi"}),({"��","gong"}),
({"��","fu"}),({"ʱ","shi"}),({"��","ruo"}),({"��","qing"}),({"��","wen"}),({"��","wu"}),({"��","duo"}),({"��","cai"}),
({"��","chang"}),({"��","zi"}),({"��","yong"}),({"��","you"}),({"��","ren"}),({"Ϊ","wei"}),({"��","tie"}),({"��","bu"}),
({"־","zhi"}),({"��","ming"}),({"��","le"}),({"ڤ","ming"}),({"��","wu"}),({"��","ling"}),({"��","fu"}),({"��","bo"}),
({"��","dao"}),({"��","xuan"}),({"��","shao"}),({"��","he"}),({"��",""}),({"��","cui"}),({"Զ","yuan"}),({"��","dan"}),
({"��","de"}),({"",""}),({"",""}),({"",""}),({"",""}),({"",""}),({"",""}),({"",""}),({"",""}),({"",""}),({"",""}),
});

static mixed name_e = ({
({"��","ba"}),({"��","bai"}),({"��","ban"}),({"��","bin"}),({"��","bin"}),({"��","chang"}),({"��","chao"}),({"��","chen"}),
({"��","chuan"}),({"��","ding"}),({"��","ding"}),({"��","fa"}),({"��","fei"}),({"��","feng"}),({"��","feng"}),({"��","gang"}),
({"�","gang"}),({"��","guan"}),({"��","guang"}),({"��","hai"}),({"��","hu"}),({"��","hua"}),({"��","hao"}),({"��","hong"}),
({"��","ji"}),({"��","jian"}),({"��","jian"}),({"��","jian"}),({"��","jiang"}),({"��","jin"}),({"��","jie"}),({"��","jun"}),
({"��","kang"}),({"��","liang"}),({"��","lin"}),({"��","min"}),({"��","ming"}),({"��","ming"}),({"��","ning"}),({"��","pei"}),
({"��","qi"}),({"ǿ","qiang"}),({"��","rong"}),({"ɽ","shan"}),({"̩","tai"}),({"��","tao"}),({"ͦ","ting"}),({"ΰ","wei"}),
({"��","xi"}),({"��","xiang"}),({"��","xiong"}),({"��","xu"}),({"Ⱥ","qun"}),({"��","yang"}),({"��","qing"}),({"��","yi"}),
({"�","yu"}),({"��","yu"}),({"��","yu"}),({"��","zhou"}),({"��","dou"}),({"��","zhen"}),({"��","feng"}),({"��","feng"}),
({"ƽ","ping"}),({"��","chong"}),({"֮","zhi"}),({"��","fang"}),({"�","nan"}),({"��","an"}),({"��","lei"}),({"��","ning"}),
({"��","du"}),({"��","po"}),({"��","lang"}),({"��","chun"}),({"��","feng"}),({"��","yun"}),({"��","tian"}),({"��","gui"}),
({"��","qi"}),({"��","ze"}),({"��","li"}),({"��","xing"}),({"ֹ","zhi"}),({"��","mie"}),({"��","feng"}),({"��","kong"}),
({"��","zhong"}),({"ѫ","xun"}),({"��","kui"}),({"Խ","yue"}),({"��","yu"}),({"��","yi"}),({"ʤ","sheng"}),({"��","hong"}),
({"��","jin"}),({"˳","shun"}),({"��","qing"}),({"��","jun"}),({"��","xin"}),({"��","tao"}),({"��","ding"}),({"��","zheng"}),
({"��","xiu"}),({"��","shao"}),({"��","li"}),({"��","gui"}),({"͢","ting"}),({"��","zhen"}),({"��","xuan"}),({"��","rang"}),
({"��","peng"}),({"ʢ","sheng"}),({"��","rui"}),({"��","jian"}),({"��","wei"}),({"��","da"}),({"��","wang"}),({"��","zhong"}),
({"��","yong"}),({"��","qing"}),({"��","run"}),({"ͨ","tong"}),({"��","meng"}),({"¡","long"}),({"��","xin"}),({"��","song"}),
({"��","liang"}),({"��","en"}),({"Ǩ","qian"}),({"��","diao"}),({"��","bao"}),({"��","bao"}),({"ʥ","sheng"}),({"��","long"}),
({"��","you"}),({"ͤ","ting"}),({"�","dai"}),({"��","yan"}),({"ŵ","nuo"}),({"��","gu"}),({"��","gao"}),({"��","heng"}),
({"��","gui"}),({"��","chen"}),({"��","jin"}),({"��","ye"}),({"��","hen"}),({"��","hua"}),({"Ȫ","quan"}),({"��","liu"}),
({"��","yu"}),({"��","xian"}),({"��","jin"}),({"��","yi"}),({"̹","tan"}),({"��","fan"}),({"��","jing"}),({"��","xuan"}),
({"��","bing"}),({"ѩ","xue"}),({"��","ji"}),({"��","jing"}),
});

static mixed name_w = ({      //Ů��ר��
({"��","ai"}),({"��","chun"}),({"��","dan"}),({"��","fang"}),({"��","fen"}),({"��","feng"}),({"��","gu"}),({"��","hong"}),
({"��","hong"}),({"��","jiao"}),({"��","juan"}),({"��","ju"}),({"��","lan"}),({"�","lan"}),({"��","li"}),({"��","li"}),
({"��","lian"}),({"��","ling"}),({"��","lin"}),({"��","na"}),({"��","qin"}),({"��","qin"}),({"ٻ","qian"}),({"Ƽ","ping"}),
({"��","ting"}),({"ϼ","xia"}),({"��","xaing"}),({"��","yan"}),({"��","yan"}),({"Ӣ","ying"}),({"��","ying"}),({"��","yu"}),
({"��","zhen"}),({"��","zhu"}),({"��","yuan"}),({"��","jin"}),({"ܿ","yun"}),({"��","ling"}),({"ɺ","shan"}),({"ܽ","fu"}),
({"�","xian"}),({"�","jin"}),({"��","yao"}),({"��","xiang"}),({"��","rong"}),({"��","ruo"}),({"��","meng"}),({"��","yi"}),
({"",""}),
});

void set_random_name(string gender)
{
	string l_c, l_e, f_c, f_e, f_c_e, f_e_e;
	int    i, j, k;
	
	i = random(sizeof(xing));
	if (stringp(gender) && gender == "Ů��"){
		j = random(sizeof(name_w));
		k = random(sizeof(name_w));
		if ( k == j ) k = random(sizeof(name_w)) / 2;
		f_c = name_w[j][0];
		f_e = name_w[j][1];
		f_c_e = name_w[k][0];
		f_e_e = name_w[k][1];
	}else{
		j = random(sizeof(name));
		k = random(sizeof(name_e));
		f_c = name[j][0];
		f_e = name[j][1];
		f_c_e = name_e[k][0];
		f_e_e = name_e[k][1];
	}

	l_c = xing[i][0];
	l_e = xing[i][1];

	set_name(l_c+f_c+f_c_e, ({ l_e+ " " + f_e + f_e_e , l_e, }));
	set("id_long", l_e + " " + f_e + f_e_e);
	set("id_short", l_e);
}