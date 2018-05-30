# 1.0v

| Pirma Strategija        |      10      |     100      |    1000     |   10000    |  100000   |
|-------------------------| ------------ | ------------ | ----------- |----------- |-----------|
|     Vector Struct       | 0.000159209s | 0.00215506 s | 0.017743 s  | 0.183133 s | 1.79775 s |
|     Class Vector        | 0.000183704 s| 0.00150519 s |0.0167218 s  | 0.19516 s  |1.82103 s  |
|     Class Vector O1     | 4.74e-06 s   | 2.5284e-05 s |0.000199901 s|0.00309373 s|0.0401655 s|
|     Class Vector O2     | 5.531e-06 s  | 1.7778e-05 s |0.000199506 s|0.00263783 s|0.0280194 s|
|     Class Vector Ox     | 3.556e-06 s  | 2.9629e-05 s |0.000152098 s|0.00367091 s|0.0303329 s|

## Naudojimosi instrukcija:
Programa pati sukuria reikiamo dydzio faila pagal vartotojo nustatytus parametrus (pavadinima bei dydi), kuri veliau ir apdoroja.

## Fun things
### Google test'ai
```c++
TEST(auto, Vidurkio_testas)
{
	std::vector<double>kazkas;
	for (int i = 5; i < 10; i++)
	{
		kazkas.push_back(i);
	}
	auto vid = vidurkis(10, kazkas);

	EXPECT_EQ(7.5, vid);
}
TEST(auto, Medianos_testas)
{
	std::vector<double>kazkas;
	for (int i = 5; i < 10; i++)
	{
		kazkas.push_back(i);
	}
	auto med = mediana(10, kazkas);
	EXPECT_EQ(7.5, med);
}
```
